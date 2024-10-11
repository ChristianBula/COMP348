#include <stdio.h>
#include <stdlib.h>
#include "calc.h" // Include the readfile header
#include "data.h"  // Include the mapping header
#include "ordering.h"  // Include the student header
#include "spreadsheet.h"  // Include the student header


float calculateTotal(int a1, int a2, int a3, int m, int e){
   float assignmentAverage = (a1+a2+a3)/3.0;

   float assignmentsWeight = 25.0;
   float assignmentsGrade = (assignmentAverage/40.0)*assignmentsWeight;

   float midtermWeight = 25.0;
   float midtermGrade = (m/25.0)*midtermWeight;

   float examWeight = 50.0;
   float examGrade = (e/40.0)*examWeight;

   float totalGrade = assignmentsGrade + midtermGrade + examGrade;

   return totalGrade;
}

char getLetterGrade(float grade, Mapping *map){
  if(grade >= map->a){
      return 'A';
    }
    else if(grade >= map->b){
      return 'B';
    }
    else if(grade >= map->c){
      return 'C';
    }
    else if(grade >= map->d){
      return 'D';
    }
    else{
      return 'F';
    }
}

int initialCountStudents(){
   char line[256];

   FILE *file_ptr = fopen("students.txt", "r");

   int a = 0;

   while (fgets(line, sizeof(line), file_ptr) != NULL){
    a++;
   }

   fclose(file_ptr);

   return a;
}

void updateLetterGrades(Mapping *map,Student *students, int studentCount){
  for(int i = 0; i < studentCount;i++){
    students[i].grade[0] = getLetterGrade(students[i].total,map);
    students[i].grade[1] = '\0';
  }
}

void setMapping(Mapping *map, float a, float b, float c, float d){
  map->a = a;
  map->b = b;
  map->c = c;
  map->d = d;
}

void changeLastName(Student *students, int studentCount){
  
  int id;
  char newLastName[20];
  
  printf("\nEnter Student ID:");
  scanf("%d",&id);
  printf("\nEnter Updated Last name:");
  scanf("%s",newLastName);

  for(int i = 0; i < studentCount;i++){
    if(students[i].id == id){
      strcpy(students[i].lastName,newLastName);
    }
  }
}

void changeExamGrade(Student *students, int studentCount){

  int id;
  int newGrade;

  printf("\nEnter Student ID:");
  scanf("%d",&id);
  printf("\nEnter Updated Grade:");
  scanf("%d",&newGrade);

  for(int i = 0; i < studentCount;i++){
    if(students[i].id == id){
      students[i].scores[4] = newGrade;
      students[i].total = calculateTotal(students[i].scores[0],students[i].scores[1],students[i].scores[2],students[i].scores[3],students[i].scores[4]);
    }
  }
}

void deleteStudent(Student *students, int studentCount){
  printSheet(students,studentCount);

  int id;
  int index;
  
  printf("\nEnter Student ID:");
  scanf("%d",&id);

  for(int i = 0; i < studentCount;i++){
    if(students[i].id == id){
      index = i;
    }
  }

  for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
  }

  students = realloc(students, (studentCount - 1) * sizeof(Student));

  printf("Student succesfully deleted");
}