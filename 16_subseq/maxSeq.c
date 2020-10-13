#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int * array,size_t n){
  if (n<=0 || array==NULL)
    return EXIT_FAILURE;
  int count=1,temp=1;
  for (int i=1;i<n,i++){
    if (array[i]>array[i-1])
      temp=temp+1;
    else if (temp>count){
      count=temp;
      temp=1;
    }
    else
      temp=1;
  }
  if (temp>count)
    count=temp;
  return count;
}
