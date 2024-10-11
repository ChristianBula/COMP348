#include <stdio.h>
#include <stdlib.h>
#include "calc.h" // Include the readfile header
#include "data.h"   // Include the mapping header
#include "ordering.h"   // Include the student header
#include "spreadsheet.h"  // Include the student header


void readFile(Student *students, Mapping *map){
   char line[256];

   FILE *file_ptr = fopen("students.txt", "r");

   char value[50];

   int a = 0;

   while (fgets(line, sizeof(line), file_ptr) != NULL){
        line[strcspn(line,"\n")] = '\0';
        char *token = strtok(line, "|");
    if (token != NULL) {
        students[a].id = atoi(token); // Assign student ID
    }

    token = strtok(NULL, "|");
    if (token != NULL) {
        strcpy(students[a].lastName, token); // Copy first name
    }

    token = strtok(NULL, "|");
    if (token != NULL) {
        strcpy(students[a].firstName, token); // Copy last name
    }

    for (int i = 0; i < 5; i++) {   
        token = strtok(NULL, "|");
        if (token != NULL) {
            students[a].scores[i] = atoi(token); // Assign score
        }
    }

    float totalGrade = calculateTotal(students[a].scores[0],students[a].scores[1],students[a].scores[2],students[a].scores[3],students[a].scores[4]);

    students[a].total = totalGrade;

    students[a].grade[0] = getLetterGrade(totalGrade,map);
    students[a].grade[1] = '\0';

    a++;
   }

   qsort(students,a,sizeof(Student), compareById);

   fclose(file_ptr);
}