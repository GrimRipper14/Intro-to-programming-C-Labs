#include "main.h"
#include <stdio.h>
#include <ctype.h>
#define MAXCHAR 50

// swap characters
void char_swap(char *x, char *y){
  char temp = *x;
  *x = *y;
  *y = temp;
}
void getData(char arr[], int *n, int counters[26]) {
  char x;
  printf("How many characters?: ");
  scanf("%d", n);
  for (int i = 0; i < *n; i++) {
    while ((x = getchar() != '\n') && x != EOF);
    printf("Enter character %d: ", i + 1);
    arr[i] = getchar();
    if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z')) {
      arr[i] = tolower(arr[i]);
      counters[arr[i] - 'a']++;
    }
  }
}
// display stats
void displayStat(int *c, int total_char)
 {
  for (int i = 0; i < 26; i++)
    printf("%c\t%d\t%.2f\n", 'a' + i, c[i], 100.0 * c[i] / total_char);
}
void displayArr(char *a, int size) {
  printf("The char array: ");
  for (int i = 0; i < size; i++)
    printf("%c", a[i]);
}
//reverse the array
void reverse(char a[], int size) {
  int last_index = size - 1;
  for (int i = 0; i < size / 2; i++){
    char_swap(&a[i], &a[last_index - i]);
  }
}

int main(void) {
  int counters[26];
  char myArr[MAXCHAR]; // MAXCHAR was hash defined to 50
  int i, total_char;

  for (i = 0; i < 26; i++)
    counters[i] = 0;

  getData(myArr, &total_char, counters);
  displayArr(myArr, total_char);
  printf("\n");
  displayStat(counters, total_char);
  reverse(myArr, total_char);
  printf("Array reversed.\n");
  displayArr(myArr, total_char);

  return 0;
}