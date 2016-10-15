#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char isPalindrom(const char *string){

  unsigned int length = strlen(string);
  
  if(length == 0){
    return 0;
  }

  char palindrom = 1;

  for(unsigned int i = 0; i < length / 2 ; i++){
    if( string[i] != string[length - 1 - i]){
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

  if(isPalindrom(string)){
    result = (char*)malloc(length);
    strcpy(result, string);
    return result;
  }

  char lastChar = string[length-1];

  long lastPosition = -1;

  for(unsigned int i = 0; i < length; i++){
    if(string[i] == lastChar) { lastPosition = i; }
  }


  printf("%d\n", lastPosition);
  if(lastPosition >= 0){
    if(string[lastPosition] == string[lastPosition - 1]){
      lastPosition--;
    }
    result = (char*)malloc(length + lastPosition);

    strcpy(result, string);
    
    for(unsigned int i = 0 ; i < lastPosition ; i++){
      result [length + i] = string[lastPosition -1 - i];
    }

  }else{
    result = (char*)malloc(length*2-1);

    strcpy(result, string);
    
    for(unsigned int i = 0; i < length; i++){
      result[length+i-1] = string[length -1 -i];
    }
  }

  return result;
}

int subseq(const char *s1, const char *s2){
  
  int length1 = strlen(s1);
  int length2 = strlen(s2);

  int matrixSizeN = length1 + 1;
  int matrixSizeM = length2 + 1;

  int strings_matrix[matrixSizeN][matrixSizeM];

  memset(strings_matrix, 0, 
    sizeof(strings_matrix[0][0]) * (matrixSizeN) * (matrixSizeM));

  int max = 0;

  for(int i =1; i < matrixSizeN; i++) {

    for(int j = 1; j < matrixSizeM; j++) {
      
      if(s1[i-1] == s2[j-1]){
          strings_matrix[i][j] = strings_matrix[i-1][j-1] + 1;
          if(max < strings_matrix[i][j]) {
            max = strings_matrix[i][j];
          }
      }

    } 

  }

  return max;

}
