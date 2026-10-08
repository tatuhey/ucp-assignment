#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "terminal.h"

#define ARRWIDTH 100
#define ARRHEIGHT 100

void display(int hgt, int wdt, int mapArray[ARRHEIGHT][ARRWIDTH]);

int main(int argc, char* argv[]) {
    /*
    2D ARRAY CREATION BELOW. NEED TO GRAB THE ARRAY SIZE FROM FILE READING
    */
    int mapArr[ARRHEIGHT][ARRWIDTH];
    int height, width, i, j;
    int valid = 0;
    int status = 0;
    /*
    FILE READING BELOW
    */

    /*https://stackoverflow.com/questions/32998105/reading-a-2d-array-from-a-file-in-c*/
    FILE* f = fopen(argv[1], "r");
    if(f == NULL) {
        perror("Error while opening file.\n");

    } else {
        
        if(fscanf(f, "%d%d", &height, &width) == 2)  {/* if it is not two values, which corresponds to height and width, exit the program*/
            if(height > 1 || height < ARRHEIGHT || width > 1 || width < ARRWIDTH) { /* if height and/or width are smaller than 1 OR bigger than defined array (100*100), exit the program*/
                
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
        display(height, width, mapArr);
    }

    
    // int k, l;
    // char t;
    /*
    display array atm
    */
    // if(status == 1) {
    //     for(k = 0; k < width + 2; k++){
    //         setForeground("red");
    //         printf("*");
    //         setForeground("reset");
    //     }
    //     printf("\n");

    //     for(i = 0; i < height; i++) {
    //         setForeground("red");
    //         printf("*");
    //         setForeground("reset");

    //         for(j = 0; j < width; j++) {

    //             if(mapArr[i][j] == 0) {
    //                 printf(" ");
    //             }
    //             else if (mapArr[i][j] == 1){
    //                 setBackground("white");
    //                 printf(" ");
    //                 setBackground("reset");
    //             }
    //             else if (mapArr[i][j] == 2) {
    //                 printf("H");
    //             }
    //             else if (mapArr[i][j] == 3) {
    //                 setBackground("red");
    //                 printf(" ");
    //                 setBackground("reset");
    //             }
    //             else if (mapArr[i][j] == 4) {
    //                 setBackground("blue");
    //                 printf("P");
    //                 setBackground("reset");
    //             }
    //             else if (mapArr[i][j] == 5)
    //                 printf("G");
    //             else
    //                 printf("?");
    //             /*
    //             printf("%d", mapArr[i][j]);
    //             */
    //         }
    //         setForeground("red");
    //         printf("*");
    //         setForeground("reset");
    //         printf("\n");

    //     }
    //     for(l = 0; l < width + 2; l++) {
    //         setForeground("red");
    //         printf("*");
    //         setForeground("reset");
            
    //     }

    //     printf("\n");
       
    // }



    return 0;
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
