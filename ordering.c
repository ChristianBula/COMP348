#include <stdio.h>
#include <stdlib.h>
#include "calc.h" // Include the readfile header
#include "data.h"   // Include the mapping header
#include "ordering.h"   // Include the student header
#include "spreadsheet.h"  // Include the student header

int compareById(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    if (studentA->id < studentB->id) {
        return -1;
    } else if (studentA->id > studentB->id) {
        return 1;
    } else {
        return 0;
    }
}

int compareByTotal(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    // Compare total grades
    if (studentA->total < studentB->total) {
        return 1; // studentB comes before studentA
    } else if (studentA->total > studentB->total) {
        return -1; // studentA comes before studentB
    } else {
        return 0; // They are equal
    }
}

int compareByExam(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    if (studentA->scores[4] < studentB->scores[4]) {
        return 1; // studentB comes before studentA
    } else if (studentA->scores[4] > studentB->scores[4]) {
        return -1; // studentA comes before studentB
    } else {
        return 0; // They are equal
    }
}

int compareByLastName(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b; 

    return strcmp(studentA->lastName, studentB->lastName);
}