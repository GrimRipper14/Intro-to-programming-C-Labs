/*
Zachary Boggs
Cop 3223C
Lab 1

1: 100
2: 90.5
3: 67.8
4: 85
5: 93
total: 436.3
avg = total / 5 = 87.36
*/
#include <stdio.h>

int main() {
  float g1, g2, g3, g4, g5;
  float total, avg;

  printf("Enter the scores for 5 subjects separated by space: ");
  scanf("%f", &g1);
  scanf("%f", &g2);
  scanf("%f", &g3);
  scanf("%f", &g4);
  scanf("%f", &g5);

  total = g1 + g2 + g3 + g4 + g5;
  avg = total / 5.0;

  printf("Total score: %f \n", total);
  printf("Percentage: %f %%", avg);
}