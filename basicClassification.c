#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int n){
  int i;
  
  for(i = 2; i<=sqrt(n); i++){
    if(n%i == 0){
      return false;
    }
  }
  return true;
}


int isStrong(int n){
  int sum = 0;
  int iterator = n;
  while(iterator>0){
    if(iterator%10>0){
      int i;
      int fact = 1;
      for (i = 1; i<=iterator%10; i++){
        fact *= i;
      }
      sum=sum + fact;
    }
    iterator = iterator/10;

  }

  if(sum == n){
    return true;
  }
  else{
    return false;
  }
}
