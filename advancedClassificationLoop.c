#include "basicClassification.c"
#include "NumClass.h"
#include <math.h>

int isArmstrong(int n){
  int nDigits = ceil(log10(n));
  int sum = 0;
  int iterator = n;
  printf("this is loop");
  while(iterator>0){
    sum += pow(iterator%10,nDigits);
    iterator = iterator/10;
  }
  if(sum == n){
    return true;
  }
  else{
    return false;
  }
}

int isPalindrome(int n){
  int nDigits = log10(n);
  int i = 0;
  while(i < nDigits-i){
    int leftNum = (int)((n/pow(10,nDigits-i)))%10;
    int rightNum = (int)((n/pow(10,i)))%10;

    if(leftNum != rightNum){
      return false;
    }
    i++;
  }
  return true;
}
