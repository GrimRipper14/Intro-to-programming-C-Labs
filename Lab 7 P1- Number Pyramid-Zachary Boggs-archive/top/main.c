// Zachary Boggs
// COP 3223C
// 10/8/23

#include <stdio.h>
#include "main.h"

//sets up the print triangle function
void print_triangle(int max_value){
  for(int i = 1; i<= max_value; i++){
    for(int j = 1; j<= max_value - i; j++){
      printf(" ");
    }
    for(int j = 1; j <= i; j++){
      printf("%d", j);
    }
    for(int j = i - 1; j>= 1; j--){
      printf("%d", j);
    }
    printf("\n");
  }
}

int main(void) {
    //variables
  int choice;
  int totaltriangles = 0;

//doing the do while loop to set up the user input
  do {
    int max_value;
    printf("Enter max value: ");
    scanf("%d", &max_value);
   
    if(max_value >= 1){
    print_triangle(max_value);
    totaltriangles++;
  } else{
    printf("Invalid input. Please enter a positive integer.\n");
  }
  printf("Enter 0 for exit or any other digit to continue: ");
  scanf("%d", &choice);
  } while(choice != 0);
  printf("Total triangle printed: %d\n", totaltriangles);
  return 0;
}