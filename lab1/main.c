#define _XOPEN_SOURCE 700 // for use getline
#include <stdio.h>
#include "mystring.h"

int main(int argc, char **argv){


  //getline(&input, &size, stdin);


      int size = 0;
    double *arr = txt2double("55.12;0.3;11.07", &size);
   for (int i = 0; i < size; i++)
    {
        printf("5 - arr[%d] = %.4f\n", i, arr[i]);
    }

    if (size == 0)
        printf("5 - (size = 0)\n");

  return 0;
}
