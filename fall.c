#include<stdio.h>
#include<stdlib.h>
#include"fall.h"
#include"newSleep.h"
#include"display.h"

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