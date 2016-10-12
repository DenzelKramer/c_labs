#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char isPalindrom(char *string){

  unsigned int length = strlen(string) - 2;
  if(length == 0){
    return 0;
  }

  char palindrom = 1;

  for(unsigned int i = 0; i < length / 2 + length % 2; i++){
    if( string[i] != string[length-i]){
      palindrom = 0;
    }
  }

  return palindrom;

}

int substr(const char *string1, const char *string2){

  unsigned int length1 = strlen(string1);
  unsigned int length2 = strlen(string2);
  char isEquals = 0;

  if(length2 > length1) return -1;

  for(unsigned int i = 0; i < length1 - length2 + 1; i++){

    isEquals = 1;

    for(unsigned int j = 0; j < length2; j++){
        if(string1[i+j] != string2[j]){
          isEquals = 0;
        }
    }

    if(isEquals){
      return i;
    }

  }

  return -1;
}

char* makepal(const char *string){

  char *result;

  unsigned int length = strlen(string);

  char lastChar = string[length-1];

  unsigned int lastPosition = -1;

  for(unsigned int i = 0; i < length-1; i++){
    if(string[i] == lastChar) lastPosition = i;
  }

  if(lastPosition >= 0){

    result = (char*)malloc(length + lastPosition);

    strcpy(result, string);
    printf("%d\n", lastPosition);
    for(unsigned int i = 0 ; i < lastPosition ; i++){
      printf("%d %d %c\n", i, lastPosition, string[lastPosition]);
      result [length + i] = string[lastPosition -1 - i];
    }

  }else{
    result = (char*)malloc(length*2);

    strcpy(result, string);

    for(unsigned int i = 0; i < length; i++){
      result[length+i] = string[length-i];
    }
  }

  return result;
}

int subseq(const char *s1, const char *s2){

  return 0;
}
