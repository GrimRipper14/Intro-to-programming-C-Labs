// Zachary Boggs
// COP 3223C
// 9/21/23

#include "main.h"
#include <stdio.h>
// RW = roomwidth RL = Roomlength
// DL = desklength DW = deskwidth
int sizeCheck(int RL, int RW, int DL, int DW) {
  int temp;

  // adjusts RL to be more then RW
  if (RL < RW) {
    temp = RL;
    RL = RW;
    RW = temp;
  }

  // adjusts DL to be more then DW
  if (DL < DW) {
    temp = DL;
    DL = DW;
    DW = temp;
  }

  // compates the DW/DL to the RW/RL
  if (DW <= RW && DL <= RL) {
    return 1;
  } else {
    return 0;
  }
}

int main(void) {

  // declare 4 variables
  int RL, RW, DL, DW;

  // ask for the room measurements
  printf("Enter the length and width of the room: ");
  scanf("%d%d", &RL, &RW);

  // adk for desk measurements
  printf("Enter the length and width of the desk: ");
  scanf("%d%d", &DL, &DW);

  if (sizeCheck(RL, RW, DL, DW)) {
    printf("the desk will fit in the room.");
  } else {
    printf("the desk will not fit in the room.");
  }

  return 0;
}