#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "terminal.h"
#include "newSleep.h"

#define ARRWIDTH 100
#define ARRHEIGHT 100

/*gotta be its own file*/
void clearDisplay(int h, int w, int arr[ARRHEIGHT][ARRWIDTH]);
void display(int hgt, int wdt, int mapArray[ARRHEIGHT][ARRWIDTH]);

/*another one*/
void playerTransversal(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int * playerH, int * playerW);
void goalTransversal(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int * gH, int * gW);

void moveLeft(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveRight(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveUp(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveDown(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);

int checkFloor(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW);
void fallAnimation(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);

int main(int argc, char* argv[]) {
    /*
    2D ARRAY CREATION BELOW. NEED TO GRAB THE ARRAY SIZE FROM FILE READING
    */
    /* not malloc method*/
    int mapArr[ARRHEIGHT][ARRWIDTH];
    int height, width, i, j;
    int valid = 0;
    int status = 0;
    char ch = 'm';
    int posW = -1;
    int posH = -1;
    int prv = 0;
    int goalW = -1;
    int goalH = -1;
    /*
    FILE READING BELOW
    */

    /*https://stackoverflow.com/questions/32998105/reading-a-2d-array-from-a-file-in-c*/
    FILE* f = fopen(argv[1], "r");
    if(f == NULL) {
        perror("Error while opening file.\n");

    } else {
        
        if(fscanf(f, "%d%d", &height, &width) == 2)  {/* if it is not two values, which corresponds to height and width, exit the program*/
            if(height >= 1 && height < ARRHEIGHT && width >= 1 && width <= ARRWIDTH) { /* if height and/or width are smaller than 1 OR bigger than defined array (100*100), exit the program*/
                for(i = 0; i < height; i++) {
                    for(j = 0; j < width; j++) {
                        if(fscanf(f, "%d", &mapArr[i][j]) != 1)
                            valid = 1;
                    }
                }

                if(valid || ferror(f)) {
                    perror("Error reading data.");
                } else {
                    status = 1;
                }

            } else {
                printf("Error. Dimension mismatch.\n");
            }

        } else {
            printf("Error. Map size is incorrect.\n");
        }

        fclose(f);
    }

    if(status == 1) {
        goalTransversal(height, width, mapArr, &goalH, &goalW);

        system("clear");
        clearDisplay(height, width, mapArr);

        printf("Press w to move UP\nPress s to move DOWN\nPress a to move LEFT\nPress d to move RIGHT\nPress u to UNDO\nPress 0 to EXIT\n");

        while(ch != '0'){
            disableBuffer();
            scanf(" %c", &ch);
            enableBuffer();

            if(ch != 'a' && ch != 'w' && ch != 's' && ch != 'd' && ch != 'u' && ch != '0'){
                printf("Invalid entry\n");
            } else {
                playerTransversal(height, width, mapArr, &posH, &posW);

                if (ch == 'd')
                    moveRight(height, width, mapArr, posH, posW, &prv);
                else if (ch == 'a')
                    moveLeft(height, width, mapArr, posH, posW, &prv);
                else if (ch == 'w')
                    moveUp(height, width, mapArr, posH, posW, &prv);
                else if (ch == 's') 
                    moveDown(height, width, mapArr, posH, posW, &prv);

                playerTransversal(height, width, mapArr, &posH, &posW);

                if (checkFloor(height, width, mapArr, posH, posW) == 0)
                    fallAnimation(height, width, mapArr, posH, posW, &prv);
            }

            if (prv == 5){
                system("clear");
                clearDisplay(height, width, mapArr);
                printf("\n");
                printf("You win!\n");
                ch = '0';
            } else if (prv == 3) {
                system("clear");
                clearDisplay(height, width, mapArr);
                printf("\n");
                printf("You lost!\n");
                ch = '0';
            } else{
                system("clear");
                clearDisplay(height, width, mapArr);
            }

        }
    }
 
    return 0;
}

void clearDisplay(int h, int w, int arr[ARRHEIGHT][ARRWIDTH]){
    system("clear");
    display(h, w, arr);
    newSleep(1.25);
}

void display(int hgt, int wdt, int arr[ARRHEIGHT][ARRWIDTH]) {
    int i, j, k, l;
    char t;

    for(k = 0; k < wdt + 2; k++){
        setForeground("red");
        printf("*");
        setForeground("reset");
    }
    printf("\n");

    for(i = 0; i < hgt; i++) {
        setForeground("red");
        printf("*");
        setForeground("reset");

        for(j = 0; j < wdt; j++) {

            if(arr[i][j] == 0) {
                printf(" ");
            }
            else if (arr[i][j] == 1){
                setBackground("white");
                printf(" ");
                setBackground("reset");
            }
            else if (arr[i][j] == 2) {
                printf("H");
            }
            else if (arr[i][j] == 3) {
                setBackground("red");
                printf(" ");
                setBackground("reset");
            }
            else if (arr[i][j] == 4) {
                setBackground("blue");
                printf("P");
                setBackground("reset");
            }
            else if (arr[i][j] == 5)
                printf("G");
            else
                printf("?");
            /*
            printf("%d", mapArr[i][j]);
            */
        }
        setForeground("red");
        printf("*");
        setForeground("reset");
        printf("\n");

    }
    for(l = 0; l < wdt + 2; l++) {
        setForeground("red");
        printf("*");
        setForeground("reset");
        
    }

    printf("\n");
       
}

/*
harus di edit utk retunring coordianates of players
*/
void playerTransversal(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int * playerH, int * playerW) {
    int kk;
    int ll;
    int foundFlag = 0;
    for(kk = 0; kk < h; kk++) {
        for(ll = 0; ll < w; ll++) {
            if(arr[kk][ll] == 4) {
                * playerW = ll;
                * playerH = kk;
                foundFlag = 1;
            }
        }
    }
    if(foundFlag == 0)
        printf("Player is not found\n");
}

void goalTransversal(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int * gH, int * gW) {
    int ii;
    int jj;
    int foundFlag = 0;
    for(ii = 0; ii < h; ii++) {
        for(jj = 0; jj < w; jj++) {
            if(arr[ii][jj] == 5) {
                * gH = ii;
                * gW = jj;
                foundFlag = 1;
            }
        }
    }
    if(foundFlag == 0)
        printf("Goal is not found\n");
}

void moveLeft(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {
    if (pW - 1 >= 0 && (arr[pH][pW - 1] == 0 || arr[pH][pW - 1] == 2 || arr[pH][pW - 1] == 5)) {
    
        arr[pH][pW] = * prv;
        *prv = arr[pH][pW - 1];
        arr[pH][pW - 1] = 4;
        
    }
}

void moveRight(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {
    if (pW + 1 < w && (arr[pH][pW + 1] == 0 || arr[pH][pW + 1] == 2 || arr[pH][pW + 1] == 5)) { /* 0 == empty, 2 == ladder, 5 == goal*/
        arr[pH][pW] = * prv;
        *prv = arr[pH][pW + 1];
        arr[pH][pW + 1] = 4;
        
    }
}

void moveUp(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {
    if (pH - 1 >= 0 && (arr[pH - 1][pW] == 2 || (*prv == 2 && arr[pH - 1][pW] != 1))) {
        arr[pH][pW] = * prv;
        *prv = arr[pH - 1][pW];
        arr[pH - 1][pW] = 4;
    }
}

void moveDown(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {
    if (pH + 1 < h && (arr[pH + 1][pW] == 2 || (*prv == 2 && arr[pH + 1][pW] != 1))) {
        arr[pH][pW] = * prv;
        *prv = arr[pH + 1][pW];
        arr[pH + 1][pW] = 4;
    }
}

int checkFloor(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW) {
    int flag = 0;

    if (pH == h - 1){
        flag = 1;
    } else if (pH + 1 < h) {
        if(arr[pH + 1][pW] == 1 || arr[pH + 1][pW] == 2) {
            flag = 1;
        } else
            flag = 0;
    }

    return flag;
}   

void fallAnimation(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {

    while(checkFloor(h, w, arr, pH, pW) == 0 && pH + 1 < h){
        arr[pH][pW] = *prv;
        *prv = arr[pH + 1][pW];
        arr[pH + 1][pW] = 4;


        pH++;

        system("tput cup 0 0");
        display(h, w, arr);

        

        newSleep(0.2);
    }
   
   
}