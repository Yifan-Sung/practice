#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void rotate(char matrix[10][10]){
  char temp[10][10];
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      temp[i][j]=matrix[9-j][i];
    }
  }
  for(int j=0;j<10;j++){
    for(int i=0;i<10;i++){
      matrix[i][j]=temp[i][j];
    }
  }
  return ;
}
