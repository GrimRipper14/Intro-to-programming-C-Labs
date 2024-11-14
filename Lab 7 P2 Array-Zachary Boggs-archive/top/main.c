//Zachary Boggs
//10/10/23
//COP 3223C

#include <stdio.h>
#include "main.h"

#define SIZE 5

void display(int Arr[], int size){
  for(int i = 0; i<size; i++){
    printf("%d ", Arr[i]);
  }
  printf("\n");
}

//sets up the addition of the numbers
int sumArray(int Arr[], int size){
  int sum = 0;
  for(int i = 0; i<size; i++){
    sum+= Arr[i];
  }
  return sum;
}

//sets up finding the max of the numbers
int findMax(int Arr[], int size){
  int max = Arr[0];
  for(int i =1; i<size; i++){
    if(Arr[i] > max){
      max = Arr[i];
    }
  }
  return max;
}

//sets up doubling the numbers
int getDouble(int data){
  return data * 2;
}

int main(void) {
  int myArray[SIZE];
  //allows the user to input five numbers
  for(int i =0; i< SIZE; i++){
    printf("Enter number %d: ", i+1);
    scanf("%d", &myArray[i]);
  }
  printf(" ");
  display(myArray, SIZE);

// prints the sum of the arrays
  int sum = sumArray(myArray, SIZE);
  printf("The sum of myArray is: %d\n", sum);

//prints the maximun value of the numbers
  int max = findMax(myArray, SIZE);
  printf("The max value of myArray is: %d\n", max);

// prints the value from doubling the numbers
  for(int i = 0; i<SIZE; i++){
    int doubled = getDouble(myArray[i]);
    printf("Double of %d is %d\n", myArray[i], doubled);
  }
// reverses the order of the numbers
  int revArray[SIZE];
  for(int i = 0; i<SIZE; i++){
    revArray[i] = myArray[SIZE - 1 - i];
  }

  printf("Now the following data are from RevArray\n ");
  display(revArray, SIZE);

  int revSum = sumArray(revArray, SIZE);
  printf("The sum of revArray is: %d\n", revSum);

  int revMax = findMax(revArray, SIZE);
  printf("The max value of revArray is: %d\n", revMax);

  for(int i =0; i<SIZE; i++){
    int doubled = getDouble(revArray[i]);
    printf("Double of %d is %d\n", revArray[i], doubled);
  }
  return 0;
}
