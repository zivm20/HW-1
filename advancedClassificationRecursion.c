#include "basicClassification.c"
#include "NumClass.h"
#include <math.h>

//recursive helper function
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





//recursive helper function
static int isPalindromeRec(int n,int flg,int nDigits, int index){

  if(index < nDigits-index){
    int leftNum = (int)((n/pow(10,nDigits-index)))%10;
    int rightNum = (int)((n/pow(10,index)))%10;
    if(leftNum != rightNum){
      flg = false;
    }

    return isPalindromeRec(n ,flg,nDigits,index+1);
  }
  return flg;
}

int isPalindrome(int n){
  int nDigits = log10(n);
  return isPalindromeRec(n,true,nDigits,0);
}
