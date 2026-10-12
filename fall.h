#ifndef FALL_H
#define FALL_H

#define ARRWIDTH 100
#define ARRHEIGHT 100

int checkFloor(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW);
void fallAnimation(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);

#endif