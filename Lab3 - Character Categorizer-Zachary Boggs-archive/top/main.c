// Zachary Boggs
// COP 3223C
// 9/13/23

#include <math.h> //sqrt
#include <stdio.h>

// takes in user input
int main() {
  printf("Enter a character: \n");
  char c;
  scanf("%c", &c);

  // code to print upper position
  if (c >= 'A' && c <= 'Z') {
    printf("%c is a capital letter.", c);
    int pos = c - 'A' + 1;
    printf("The letter number is %d in the alphabet. \n", pos);
  }

  // code to print lower position
  else if (c >= 'a' && c <= 'z') {
    printf("%c is a small case letter.", c);
    int pos = c - 'a' + 1;
    printf("The letter number is %d in the alphabet. \n", pos);
  }

  // code to square root the number inputed
  else if (c >= '0' && c <= '9') {
    printf("%c is a digit. \n", c);
    double root = sqrt(c - '0');
    printf("The square root of %c is %.2lf", c, root);
  }

  // special character response
  else {
    printf("%c is a special symbol.", c);
  }
}