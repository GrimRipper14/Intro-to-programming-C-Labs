// Zachary Boggs
// COP 3223C
// 9/21/23

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // creates random number generator
  srand(time(NULL));
  int A, B, R;
  printf("Enter Center x,y coordinate and radius: \n");
  scanf("%d %d %d", &A, &B, &R);

  // setting the random number generator
  int x = rand() % (A + R + 3) + 1;
  int y = rand() % (B + R + 3) + 1;

  // distance formula
  double distance = sqrt(pow(x - A, 2) + pow(y - B, 2));
  printf("The generated coordinate is: (%d, %d)\n", x, y);

  // setting up if the point is inside, outside or on the circle
  if (distance < R) {
    printf("Point is inside circle\n");
  } else if (distance == R) {
    printf("Point if on the circle\n");
  } else {
    printf("Point is outside the circle\n");
  }

  return 0;
}