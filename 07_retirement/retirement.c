#include <stdio.h>
#include <stdlib.h>

struct retire_info {
  int months;
  double contribution;
  double rate_of_return;
}; typedef struct retire_info reinfo;


void retirement (int startAge,double initial,reinfo working, reinfo retired) {

  int mon=startAge*12+3;
  int start=startAge*12+3;
  double balance = initial;
  int Age=startAge;

  for(int i = start; i < working.months+start; i++) {
    printf("Age %d month %d you have %.2lf\n", Age, mon%12, balance);
    balance = balance*working.rate_of_return+working.contribution+balance;
    mon = mon+1;
    Age=mon/12;
  }

  int m=mon;
  for(int j=m+1;j<=m+retired.months;j++){
    printf("Age %d month %d you have %.2lf\n",Age,mon%12,balance);
    balance=balance*retired.rate_of_return+retired.contribution+balance;
    mon=mon+1;
    Age=mon/12;
  }
}




int main() {
  /* My first C programe */

  reinfo working;
  reinfo retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(27,21345,working,retired);


  return EXIT_SUCCESS;
}
