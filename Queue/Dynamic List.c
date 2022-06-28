#include<stdio.h>
#include<stdlib.h>

int main () {

   int *pnt;
   pnt = malloc(sizeof(int) * 4);

   int *hehe = pnt;

   pnt[0] = 5;
   pnt[1] = 1;
   pnt[2] = 2;
   pnt[3] = 3;

    for (int i = 0; i < 4; i++){

        printf("%d\n", *hehe);
        hehe++;

    }

    return 0;
}