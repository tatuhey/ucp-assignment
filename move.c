#include<stdio.h>
#include<stdlib.h>
#include"move.h"

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
