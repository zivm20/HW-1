#include "basicClassification.c"
#include "NumClass.h"
#include <math.h>

static int isArmstrongRec(int n,int sum,int nDigits){

  if(n > 0){
    sum += pow(n%10,nDigits);
  }
  else{
    return sum;
  }

  return isArmstrongRec(n/10, sum, nDigits);
}


int isArmstrong(int n){
  int nDigits = ceil(log10(n));
  int sum = isArmstrongRec(n,0,nDigits);
  if(sum == n){
    return true;
  }
  else{
    return false;
  }
}






static int isPalindromeRec(int n,int flg){
  if(n>0){
    int nDigits = log10(n);
    int leftNum = n/pow(10,nDigits);
    int rightNum = n%10;
    if(leftNum != rightNum){
      flg = false;
    }
    int newN = (n % (int)(pow(10,nDigits)) )/10;
    return isPalindromeRec(newN ,flg);
  }
  return flg;
}

int isPalindrome(int n){
  return isPalindromeRec(n,true);
}
