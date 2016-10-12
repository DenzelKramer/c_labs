#define _XOPEN_SOURCE 700 // for use getline
#include <stdio.h>
#include "mystring.h"

int main(int argc, char **argv){

  char *input = NULL;
  size_t size;

  //getline(&input, &size, stdin);

  printf("%s\n", makepal("asd"));

  return 0;
}
