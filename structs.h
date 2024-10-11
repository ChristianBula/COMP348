#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Mapping structure
typedef struct {
    float a;
    float b;
    float c;
    float d;
} Mapping;

// Define the Student structure
typedef struct {
    int id;
    char lastName[50];    
    char firstName[50];  
    int scores[5];
    float total;
    char grade[2];
} Student;

#endif