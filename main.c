#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "terminal.h"
#include "newSleep.h"
#include "display.h"
#include "transversal.h"
#include "move.h"

#define ARRWIDTH 100
#define ARRHEIGHT 100



/*another one*/

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


/*
harus di edit utk retunring coordianates of players
*/

