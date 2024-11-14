// Zachary Boggs
// Cop3223C Lab 2
// 9/7/2023

#include <stdio.h>

int main() {
  int num;
  int d1, d2, d3, d4, d5;

  // user input for 5 digits and scans
  printf("Enter a five digit number: ");
  scanf("%d", &num);

  d1 = num % 10;
  num = num / 10;
  d2 = num % 10;
  num = num / 10;
  d3 = num % 10;
  num = num / 10;
  d4 = num % 10;
  num = num / 10;
  d5 = num % 10;
  num = num / 10;

  // takes the numbers given and uses multiplication to move their location
  num = d1 * 10000 + d2 * 1000 + d3 * 100 + d4 * 10 + d5;
  printf("Reverse Number: %d \n", num);
  int sum = d1 + d2 + d3 + d4 + d5;

  // adds all the numbers up to create one number
  printf("Sum of Digits: %d + %d + %d + %d + %d = %d", d5, d4, d3, d2, d1, sum);
  return 0;
}