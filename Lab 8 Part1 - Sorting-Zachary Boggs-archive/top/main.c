// Zachary Boggs
// cop 3223c
// sorting arrays
// 10/25/23
#include <stdio.h>
#include "main.h"

#define MAX_SIZE 50000


//this function copies the array so it can be placed elsewhere
void copy_array(int destination[], int source[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

//this function dispalys the array so it can be printed
void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//this function swaps the values of the elements
void bubble_sort(int arr[], int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    printf("\nIteration# %d\n", i + 1);
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {

        //swapping arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
      display_array(arr, size);
    }
  }
}

//this function performs the selection sort and displays the steps
void selection_sort(int arr[], int size) {
  int temp;
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        //swapping arr[j] and arr[j+1]
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;

        printf("\nIteration# %d\n", i + 1);
        for (int k = 0; k < size; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main(void) {
    int arr[MAX_SIZE];
    int size;

    //asking the user for input
    printf("How many numbers to sort?\n");
    scanf("%d", &size);

    //allows for the user to input multiple numbers
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting:\n");
    display_array(arr, size);

    //sorting with use of the bubble_sort function
    int bubble_sort_arr[MAX_SIZE];
    copy_array(bubble_sort_arr, arr, size);

    printf("\nUsing Bubble sort\n");
    bubble_sort(bubble_sort_arr, size);

    printf("\nSorted array using Bubble Sort:\n");
    display_array(bubble_sort_arr, size);

    //sorting with use of the selection_sort function
    int selection_sort_arr[MAX_SIZE];
    copy_array(selection_sort_arr, arr, size);

    printf("\nUsing Selection sort\n");
    printf("\n");
    selection_sort(selection_sort_arr, size);

    printf("\nSorted array using Selection Sort:\n");
    display_array(selection_sort_arr, size);

    return 0;
}