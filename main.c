#include <stdio.h>
#include <stdlib.h>

#define ARRWIDTH 100
#define ARRHEIGHT 100

int main(void) {
    /*
    2D ARRAY CREATION BELOW. NEED TO GRAB THE ARRAY SIZE FROM FILE READING
    */
    int mapArr[ARRHEIGHT][ARRWIDTH];
    
    int height, width, i, j;
    /*
    FILE READING BELOW
    */

    /*https://stackoverflow.com/questions/32998105/reading-a-2d-array-from-a-file-in-c*/
    FILE* f = fopen("map.txt", "r");
    if(f == NULL) {
        perror("Error while opening map.txt\n");
    } else {
        
        if(fscanf(f, "%d%d", &height, &width) != 2) /* if it is not two values, which corresponds to height and width, exit the program*/
            exit(1);
        if(height < 1 || height > ARRHEIGHT || width < 1 || width > ARRWIDTH) /* if height and/or width are smaller than 1 OR bigger than defined array (100*100), exit the program*/
            exit(1);


        for(i = 0; i < height; i++) {
            for(j = 0; j < width; j++) {
                if(fscanf(f, "%d", &mapArr[i][j] != 1))
                    exit(1);
            }
        }
        
        if(ferror(f)) {
            perror("Error reading from map.txt\n");
        }

        fclose(f);
    }


    /*
    display array atm*/
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d", mapArr[i][j]);
        }
        printf("\n");
    }


    return 0;
}