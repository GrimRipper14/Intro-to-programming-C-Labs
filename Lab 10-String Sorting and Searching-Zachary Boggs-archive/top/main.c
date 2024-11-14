// Zachary Boggs
// 11/8/23
// COP 3223C

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXSTRINGS 100
#define MAXLENGTH 51 // maximum string length will be 50 + 1 for '\0'

void selection_sort(char names[][MAXLENGTH], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(names[i], names[j]) > 0) {
        char temp[MAXLENGTH];
        strcpy(temp, names[i]);
        strcpy(names[i], names[j]);
        strcpy(names[j], temp);
      }
    }
  }
}

void to_lowercase(char *str) {
  while (*str) {
    *str = tolower((unsigned char)*str);
    str++;
  }
}
void print_sorted_names(char names[][MAXLENGTH], int n) {
  for (int i = 0; i < n; i++) {
    printf("%s\n", names[i]);
  }
}
int main(void) {
  int n;
  char names[MAXSTRINGS][MAXLENGTH];
  // takes input for the names
  printf("Enter how many names: ");
  scanf("%d", &n);
  getchar();
  // sorts the names
  for (int i = 0; i < n; i++) {
    printf("Name %d: ", i + 1);
    fgets(names[i], MAXLENGTH, stdin);
    names[i][strlen(names[i]) - 1] = '\0';
    to_lowercase(names[i]);
  }
  selection_sort(names, n);
  // prints sorted names

  printf("Sorted Names: \n");
  print_sorted_names(names, n);
  char search[MAXLENGTH];
  while (1) {
    // tkaes in search term
    printf("\nEnter search string: ");
    fgets(search, MAXLENGTH, stdin);
    search[strlen(search) - 1] = '\0';
    to_lowercase(search);
    if (strcmp(search, "exit") == 0) {
      printf("bye!\n");
      break;
    } else {
      int found = 0;
      for (int i = 0; i < n; i++) {
        if (strstr(names[i], search) != NULL) {
          printf("%s\n", names[i]);
          found = 1;
        }
      }
      // prints if name is not found
      if (!found) {
        printf("not found\n");
      }
    }
  }
  return 0;
}