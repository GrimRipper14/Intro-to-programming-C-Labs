// Zachary Boggs
// COP 3223C
// 10/3/23
#include "main.h"
#include <stdio.h>

int main(void) {
  // variables
  int n;
  printf("Enter your n: ");
  scanf("%d", &n);
  double sum = 0.0;
  // generate all the numbers from 1 to a
  for (int i = 1; i <= n; i++) {
    long long fact = factorial(i);
    long long powValue = power(i, i);
    sum += (double)powValue / fact;
  }
  // avoids integer division by multipying 1.0
  printf("Summation of the series from 1 to %d is: %.2f\n", n, sum);
  return 0;
}

long long factorial(int n) {
  long long fact = 1;
  // generating all numbers from 1 to n
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}
long long power(int x, int y) {
  long long result = 1;
  while (y > 0) {
    result *= x;
    y--;
  }
  return result;
}