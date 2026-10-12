#ifndef MOVE_H
#define MOVE_H

#define ARRWIDTH 100
#define ARRHEIGHT 100

void moveLeft(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveRight(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveUp(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);
void moveDown(int h, int w, int arr[ARRHEIGHT][ARRWIDTH], int pH, int pW, int * prv);

#endif
