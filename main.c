#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "terminal.h"
#include "newSleep.h"
#include "display.h"
#include "transversal.h"
#include "move.h"
#include "fall.h"

#define ARRWIDTH 100
#define ARRHEIGHT 100

typedef struct LinkedListNode {
    void * data;
    struct LinkedListNode * next;    
} LinkedListNode; /*not enough time*/


int main(int argc, char* argv[]) {

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

    /* too many variables */

    /*
    FILE READING BELOW
    */
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
    
    if(status == 1) { /*if file read is correct*/
        goalTransversal(height, width, mapArr, &goalH, &goalW); /*find where is goal*/

        system("clear"); /*clear screen to get ready to show screen*/
        clearDisplay(height, width, mapArr); /*show game screen*/

        printf("Press w to move UP\nPress s to move DOWN\nPress a to move LEFT\nPress d to move RIGHT\nPress u to UNDO\nPress 0 to EXIT\n"); /*print menu first time*/

        /*UNDO DOES NOT WORK*/

        while(ch != '0'){   /*while not selecting EXIT*/
            disableBuffer(); /*from supplementary*/
            scanf(" %c", &ch); /*receive input without enter*/
            enableBuffer();

            if(ch != 'a' && ch != 'w' && ch != 's' && ch != 'd' && ch != 'u' && ch != '0'){ /*if entries are besides the menu, invalid*/
                printf("Invalid entry\n");
            } else {
                playerTransversal(height, width, mapArr, &posH, &posW); /*find where player is right now*/

                if (ch == 'd')
                    moveRight(height, width, mapArr, posH, posW, &prv); /*press d, move right*/
                else if (ch == 'a')
                    moveLeft(height, width, mapArr, posH, posW, &prv); /*press a, move left*/
                else if (ch == 'w')
                    moveUp(height, width, mapArr, posH, posW, &prv); /*press w, move up*/
                else if (ch == 's') 
                    moveDown(height, width, mapArr, posH, posW, &prv); /*press s, move down*/

                playerTransversal(height, width, mapArr, &posH, &posW); /*refresh player location*/

                if (checkFloor(height, width, mapArr, posH, posW) == 0) /*if floor does not exist, fall*/
                    fallAnimation(height, width, mapArr, posH, posW, &prv);
            }

            if (prv == 5){ /*if player is in goal, you win and exit*/
                system("clear");
                clearDisplay(height, width, mapArr);
                printf("\n");
                printf("You win!\n");
                ch = '0';
            } else if (prv == 3) { /* if in dangerzone, lost and exit */
                system("clear");
                clearDisplay(height, width, mapArr);
                printf("\n");
                printf("You lost!\n");
                ch = '0';
            } else{
                system("clear"); /*otherwise, clear and display screen again*/
                clearDisplay(height, width, mapArr);
            }

        }
    }
 
    return 0;
}
