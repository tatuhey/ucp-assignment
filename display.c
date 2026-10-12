#include<stdio.h>
#include<stdlib.h>
#include"display.h"
#include"color.h"
#include"newSleep.h"

void clearDisplay(int h, int w, int arr[ARRHEIGHT][ARRWIDTH]){
    system("clear");
    display(h, w, arr);
    newSleep(1.25);
}

void display(int hgt, int wdt, int arr[ARRHEIGHT][ARRWIDTH]) {
    int i, j, k, l;

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
            else if (arr[i][j] == 5){
                setBackground("green");
                printf("G");
                setBackground("reset");
            }

                
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
