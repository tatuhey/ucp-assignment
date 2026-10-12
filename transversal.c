#include<stdio.h>
#include<stdlib.h>
#include"transversal.h"

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
