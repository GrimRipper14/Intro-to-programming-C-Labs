// Zachary Boggs
// 10/21/23
// COP 3223C

#include "main.h"
#include <stdio.h>
#define ROWS 10
#define COLUMNS 10

void FillData(int A[][COLUMNS], int r, int c);
void Display(int A[][COLUMNS], int r, int c);
void Multiply(int M1[][COLUMNS], int r1, int c1, int M2[][COLUMNS], int r2,int c2);

int main(void) {
  int matrix1[ROWS][COLUMNS], matrix2[ROWS][COLUMNS];
  int r1, r2, c1, c2;

  printf("Working for Matrix 1\n");
  printf("Enter number of rows and columns: ");
  scanf("%d %d", &r1, &c1);
  FillData(matrix1, r1, c1);

  printf("Working for Matrix 2\n");
  printf("Enter number of rows and columns: ");
  scanf("%d %d", &r2, &c2);
  FillData(matrix2, r2, c2);

  printf("\nDisplaying Matrix 1:\n");
  Display(matrix1, r1, c1);

  printf("\nDisplaying Matrix 2:\n");
  Display(matrix2, r2, c2);
  if (c1 != r2) {
    printf("Not valid dimensions for multiplication\n");
    return 0;
  }
  Multiply(matrix1, r1, c1, matrix2, r2, c2);
  return 0;
}

void FillData(int A[][COLUMNS], int r, int c) {
  printf("Enter data for %dx%d matrix: \n", r, c);
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      scanf("%d", &A[i][j]);
}
void Display(int A[][COLUMNS], int r, int c) {
  printf("\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      printf("%d ", A[i][j]);
  }
  printf("\n");
}
void Multiply(int matrix1[][COLUMNS], int r1, int c1, int matrix2[][COLUMNS],int r2, int c2) {
  int result[ROWS][COLUMNS];
  for (int i = 0; i < r1 ; i++) {
    for (int j = 0; j < c2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < c1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  printf("\nDisplaying Result Matrix:\n");
  Display(result, r1, c2);
}