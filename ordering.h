#ifndef ORDERING_H
#define ORDERING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h" // Include the readfile header
#include "data.h"  // Include the mapping header
#include "spreadsheet.h"  // Include the student header
#include "structs.h"

// Function prototypes
int compareById(const void *a, const void *b);
int compareByTotal(const void *a, const void *b);
int compareByExam(const void *a, const void *b);
int compareByLastName(const void *a, const void *b);

#endif //