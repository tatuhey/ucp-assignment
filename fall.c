#include<stdio.h>
#include<stdlib.h>
#include"fall.h"
#include"newSleep.h"
#include"display.h"

int checkFloor(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW) {
    int flag = 0;

    if (pH == h - 1){ /*if player is on the bottom, return 1*/
        flag = 1;
    } else if (pH + 1 < h) { /*if player is not on the bottom*/
        if(arr[pH + 1][pW] == 1 || arr[pH + 1][pW] == 2) { /*if below player is block or ladder*/
            flag = 1; /*floor exists*/
        } else
            flag = 0; /*otherwise no*/
    }

    return flag;
}   

void fallAnimation(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv) {

    while(checkFloor(h, w, arr, pH, pW) == 0 && pH + 1 < h){ /*while floor does not exists AND player is above the lowest floor*/
        arr[pH][pW] = *prv;    /*do down movement*/
        *prv = arr[pH + 1][pW];
        arr[pH + 1][pW] = 4;


        pH++; /*change player height*/

        system("tput cup 0 0"); /*from supplementary*/
        display(h, w, arr); /*display screen*/

        

        newSleep(0.2);/*from supplementary*/
    }
   
   
}