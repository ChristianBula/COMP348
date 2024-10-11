#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h" // Include the readfile header
#include "data.h"  // Include the mapping header
#include "ordering.h"  // Include the student header
#include "structs.h"

// Function prototypes
int main();
void proceed();
void printMenu();
void printSheet(Student *students,int studentCount);
void printAsterisk(int numberOfAsterisks);
void displayHistogram(Student *students, int studentCount);
void printMapping(Mapping *map);
void printMappingMenu(Mapping *map);
int printColumnSort(Student *students, int studentCount);

#endif