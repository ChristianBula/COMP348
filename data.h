#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h" // Include the readfile header
#include "ordering.h"  // Include the student header
#include "spreadsheet.h"  // Include the student header
#include "structs.h"

// Function prototypes
void readFile(Student *students, Mapping *map);

#endif // DATA_H