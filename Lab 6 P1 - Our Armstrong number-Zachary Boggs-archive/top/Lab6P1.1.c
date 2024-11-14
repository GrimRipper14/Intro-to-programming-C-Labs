// Zachary Boggs
// COP 3223C
// 10/2/23
#include "main.h"
#include <stdio.h>

int sumDigitCube(int n) {
  // variables
  int digit, sum = 0;
  while (n > 0) {
    // last digit
    digit = n % 10;
    sum += digit * digit * digit;
    // peel off last digit
    n /= 10;
  }
  return sum;
}
int main(void) {
  // variables
  int n, sum = 0;
  printf("Enter a number: \n");
  scanf("%d", &n);
  printf("The Armstrong numbers are: \n");
  // check if it is an armstrong number
  for (int i = 1; i <= n; i++) {
    sum = sumDigitCube(i);
    if (sum == i)
      printf("%d\n", sum);
  }
  return 0;
}