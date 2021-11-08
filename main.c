#include <stdio.h>

#include "NumClass.h"

int main(){
  int ans = isStrong(145);
  printf("is Strong 145: %d\n",ans);
  ans = isPrime(13);
  printf("is prime 13: %d\n",ans);
  ans = isArmstrong(407);
  printf("is armstrong 407: %d\n",ans);
  int inp = 808;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);
  inp = 52625;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);
  inp = 4334;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);
  inp = 853412;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);
  inp = 1231;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);
  inp = 1;
  ans = isPalindrome(inp);
  printf("is Palindrome %d: %d\n",inp,ans);



  return 0;
}
