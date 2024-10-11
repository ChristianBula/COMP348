#include <stdio.h>
#include <stdlib.h>
#include "calc.h" // Include the readfile header
#include "data.h"   // Include the mapping header
#include "ordering.h"  // Include the student header
#include "spreadsheet.h"  // Include the student header

int main() {
   int studentCount = initialCountStudents();
   int sortChoice = 1; //1 for ID, 2 for last name, 3 for exam, 4 for total
   int menuChoice = 0;
   int id;

   Mapping *map = (Mapping *) malloc(sizeof(Mapping) * 1);
   setMapping(map,80,70,60,50);

   Student *students_array = (Student *) malloc(sizeof(Student) * studentCount);

   readFile(students_array,map);
   while(menuChoice != 8){
      system("clear");
      printMenu();
      printf("Please chose an option:");
      scanf("%d", &menuChoice);

      if(menuChoice > 0 & menuChoice <= 8){
      switch(menuChoice){
         case 1:
           system("clear");
           printSheet(students_array, studentCount);
           proceed();
           break;
         case 2:
           system("clear");
           displayHistogram(students_array, studentCount);
           proceed();
           break;
         case 3:
           system("clear");
           sortChoice = printColumnSort(students_array, studentCount);
           proceed();
           break;
         case 4:
           system("clear");
           printSheet(students_array,studentCount);
           changeLastName(students_array,studentCount);
           if(sortChoice == 2){
            qsort(students_array,studentCount,sizeof(Student), compareByLastName);
           }
           proceed();
           break;
         case 5:
           system("clear");
           printSheet(students_array,studentCount);
           changeExamGrade(students_array,studentCount);
           updateLetterGrades(map,students_array,studentCount);
           if(sortChoice == 3){
            qsort(students_array,studentCount,sizeof(Student), compareByExam);
           }
           proceed();
           break;
         case 6:
           system("clear");
           printMappingMenu(map);

           printf("New Mapping:");
           printMapping(map);

           updateLetterGrades(map,students_array,studentCount);

           proceed();
           break;
         case 7:
           system("clear");
           deleteStudent(students_array,studentCount);
           (studentCount)--;
           proceed();
           break;
         case 8:
          break;
      }
      }else{
        printf("Please choose a valid option");
        proceed();
      }
   }
   return 0;
}

void proceed(){
  char proceed;
  printf("\nPress 'c' or 'C' to continue ");
  do{
  scanf("%c", &proceed);
  } while ( (proceed != 'c') && (proceed != 'C'));
}

void printMenu(){
   printf("Spreadsheet Menu\n");
   printf("----------------\n");
   printf("1. Display Spreadsheet\n");
   printf("2. Display Histogram\n");
   printf("3. Set Sort Column\n");
   printf("4. Update Last Name\n");
   printf("5. Update Exam Grade\n");
   printf("6. Update Grade Mapping\n");
   printf("7. Delete Student\n");
   printf("8. Exit\n");
}

void printSheet(Student *students,int studentCount){
  printf("ID    Last       First       A1  A2  A3  Midterm  Exam   Total   Grade\n");
  printf("--    ----       -----       --  --  --  -------  ----   -----   -----\n");

  for(int i = 0; i < studentCount;i++){
    printf("%-6d%-11s%-11s ", students[i].id, students[i].lastName, students[i].firstName);
    for(int j = 0; j < 3;j++){
      printf("%-4d", students[i].scores[j]);
    }

    printf("%-9d%-7d%-8.2f%-4s", students[i].scores[3], students[i].scores[4], students[i].total, students[i].grade);

    printf("\n");
  }
}

void printAsterisk(int numberOfAsterisks){
  for(int i = 0; i < numberOfAsterisks; i++){
    printf("*");
  }
  printf("\n");
}

void displayHistogram(Student *students, int studentCount){
  int intSize[20];

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int f = 0;

  for(int i = 0; i < studentCount; i++){
    switch (students[i].grade[0]){
      case 'A':
        a++;
        break;
      case 'B':
        b++;
        break;
      case 'C':
        c++;
        break;
      case 'D':
        d++;
        break;
      case 'F':
        f++;
        break;
      default:
        // code block
}
  }

  printf("COMP 348 Grade Distribution\n");
  printf("A: ");
  printAsterisk(a);
  printf("B: ");
  printAsterisk(b);
  printf("C: ");
  printAsterisk(c);
  printf("D: ");
  printAsterisk(d);
  printf("F: ");
  printAsterisk(f);
}

void printMapping(Mapping *map){
  printf(" A: >= %.2f\n",map->a);
  printf(" B: >= %.2f\n",map->b);
  printf(" C: >= %.2f\n",map->c);
  printf(" D: >= %.2f\n",map->d);
  printf(" F:  < %.2f\n",map->d);
}

void printMappingMenu(Mapping *map){
  printf("Current Mapping:\n");
  printMapping(map);

  float baselineA;
  float baselineB;
  float baselineC;
  float baselineD;

  do{
  printf("\nEnter new A baseline:");
  scanf("%f",&baselineA);
  if(baselineA < 0 || baselineA > 100){
    printf("Please Enter a value between 0 and 100");
  }
  } while ( (baselineA < 0) || (baselineA > 100));

  do{
  printf("\nEnter new B baseline:");
  scanf("%f",&baselineB);
  if(baselineB < 0 || baselineB > 100){
    printf("Please Enter a value between 0 and 100");
  }
  } while ( (baselineB < 0) || (baselineB > 100));

  do{
  printf("\nEnter new c baseline:");
  scanf("%f",&baselineC);
  if(baselineC < 0 || baselineC > 100){
    printf("Please Enter a value between 0 and 100");
  }
  } while ( (baselineC < 0) || (baselineC > 100));

  do{
  printf("\nEnter new D baseline:");
  scanf("%f",&baselineD);
  if(baselineD < 0 || baselineD > 100){
    printf("Please Enter a value between 0 and 100");
  }
  } while ( (baselineD < 0) || (baselineD > 100));

  setMapping(map,baselineA,baselineB,baselineC,baselineD);
}

int printColumnSort(Student *students, int studentCount){
  printf("Column Options\n");
  printf("-----------\n");
  printf("1. Student ID\n");
  printf("2. Last Name\n");
  printf("3. Exam\n");
  printf("4. Total\n");

  
  int menuChoice = 0;

  do{
  printf("\nPlease chose an option:");
  scanf("%d",&menuChoice);
  if(menuChoice < 1 || menuChoice > 4){
    printf("Invalid Input. Try Again\n");
  }
  } while ( (menuChoice < 1) || (menuChoice > 4));
  

  switch(menuChoice){
         case 1:
           qsort(students,studentCount,sizeof(Student), compareById);
           printf("You sorted by ID succesfully");
           break;
         case 2:
           printf("You sorted by last name succesfully");
           qsort(students,studentCount,sizeof(Student), compareByLastName);
           break;
         case 3:
           qsort(students,studentCount,sizeof(Student), compareByExam);
           printf("You sorted by exam grade succesfully");
           break;
         case 4:
           qsort(students,studentCount,sizeof(Student), compareByTotal);
           printf("You sorted by total grade succesfully");
           break;
      }

    return menuChoice;
}