#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"  // Include the mapping header
#include "ordering.h"  // Include the student header
#include "spreadsheet.h"  // Include the student header
#include "structs.h"

// Function declarations
float calculateTotal(int a1, int a2, int a3, int m, int e);
char getLetterGrade(float grade, Mapping *map);
int initialCountStudents();
void updateLetterGrades(Mapping *map,Student *students, int studentCount);
void setMapping(Mapping *map, float a, float b, float c, float d);
void changeLastName(Student *students, int studentCount);
void changeExamGrade(Student *students, int studentCount);
void deleteStudent(Student *students, int studentCount);

#endif