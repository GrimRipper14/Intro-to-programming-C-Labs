// Zachary Boggs
// COP 3223
// 11/15/23

#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTD 100  // maximum number of students
#define MAXITEMS 10 // maximum number of quizzes
#define STLEN 51    // maximum char array size. Max string length is 50.

char getLetterGrade(float score) {
  if (score >= 90)
    return 'A';
  else if (score >= 80)
    return 'B';
  else if (score >= 70)
    return 'C';
  else
    return 'F';
}

int getMaxTotalIdx(float totals[], int n) {
  int max_idx = 0;
  for (int i = 0; i < n; i++) {
    if (totals[i] > totals[max_idx])
      max_idx = i;
  }
  return max_idx;
}

void writeData(FILE *out, char ids[][STLEN], char names[][STLEN],
               float totals[], int n) {
  fprintf(out, "Summary of students:\n========\n");
  for (int i = 0; i < n; i++) {
    fprintf(out, "ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i],
            totals[i], getLetterGrade(totals[i]));
  }
  // find the student with the highest score
  int max_idx = getMaxTotalIdx(totals, n);
  fprintf(out,
          "\n========\nFirst student with the highest total is %s %s %.2f\n",
          ids[max_idx], names[max_idx], totals[max_idx]);
  fprintf(out, "Data written in summary.txt file\n");

  // Print summary to the console
  printf("Summary of students:\n========\n");
  for (int i = 0; i < n; i++) {
    printf("ID: %s Lname: %s Total: %.2f Grade: %c\n", ids[i], names[i],
           totals[i], getLetterGrade(totals[i]));
  }
  printf("\n========\nFirst student with the highest total is %s %s %.2f\n",
         ids[max_idx], names[max_idx], totals[max_idx]);
  printf("Data written in summary.txt file\n");
}

int lookup(char names[][STLEN], char key[STLEN], int n) {
  for (int i = 0; i < n; i++) {
    if (strcmp(names[i], key) == 0) // user sensitive
      return i;
  }
  return -1;
}

int main(void) {
  char ids[MAXSTD][STLEN];        // ids
  char names[MAXSTD][STLEN];      // last names
  float grades[MAXSTD][MAXITEMS]; // grades
  float totals[MAXSTD];           // totals

  // inputs file name from user
  char filename[STLEN];
  scanf("%s", filename);
  // open files
  FILE *infile, *outfile;
  infile = fopen(filename, "r");
  outfile = fopen("summary.txt", "w");
  // check if file exists
  if (infile == NULL || outfile == NULL) {
    printf("Cannot open files\n");
    exit(1);
  }
  // scans num of students and quizes
  int n, g;
  fscanf(infile, "%d %d", &n, &g);
  float quiztotal;
  int i;
  for (i = 0; i < n; i++) {
    quiztotal = 0.0;
    // scans ids and names
    fscanf(infile, "%s", ids[i]);
    fscanf(infile, "%s", names[i]);
    // scans midterm and final grades
    fscanf(infile, "%f %f", &grades[i][0], &grades[i][1]);
    // scans quiz grades
    for (int j = 2; j < g + 2; j++) {
      fscanf(infile, "%f", &grades[i][j]);
      quiztotal += grades[i][j];
    }
    // calculates final grade
    totals[i] = 0.35 * grades[i][0] + 0.40 * grades[i][1] +
                0.25 * (quiztotal * 1.0 / g);
  }
  // call write data function
  writeData(outfile, ids, names, totals, n);
  char searchname[STLEN];
  printf("Enter a last name to search: ");
  scanf("%s", searchname);
  for (int i = 0; searchname[i]; i++) {
    searchname[i] = tolower(searchname[i]);
  }

  // call lookup function and print student info
  int idx = lookup(names, searchname, n);
  if (idx != -1) {
    printf("%s was found in the list. Here is the details:\n", searchname);
    printf("ID: %s Lname: %s Total: %.2f\n", ids[idx], names[idx], totals[idx]);
    printf("Grades:\nMidterm: %.2f, Final term: %.2f, quizzes:\n",
           grades[idx][0], grades[idx][1]);
    // prints quiz grades
    for (int j = 2; j < g + 2; j++) {
      printf("%.2f ", grades[idx][j]);
    }
    printf("\n");
  } else {
    printf("%s not found in the list.\n", searchname);
  }
  // close files
  fclose(infile);
  fclose(outfile);

  return 0;
}