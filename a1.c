#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;              
    char firstName[50];  
    char lastName[50];   
    int scores[5];       
} Student;


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

void printSelection(int menuChoice){
   printf("You chose the value %d\n", menuChoice);

   char proceed;
   printf("\nPress 'c' or 'C' to continue ");
   do{
   scanf("%c", &proceed);
   } while ( (proceed != 'c') && (proceed != 'C'));

   system("clear");
}

void readFile(Student student){
   char line[256];

   FILE *file_ptr = fopen("students.txt", "r");

   char value[50];

   int a = 0;

   while (fgets(line, sizeof(line), file_ptr) != NULL){
         char *token = strtok(line,"|");
         while (token != NULL) {
            printf("%s\n", token); // Print the current token
            token = strtok(NULL, "|"); // Get the next token
         }
   }

   char proceed;
   printf("\nPress 'c' or 'C' to continue ");
   do{
   scanf("%c", &proceed);
   } while ( (proceed != 'c') && (proceed != 'C'));
}

int main() {
   Student student;
   readFile(student);
   int menuChoice = 0;
   while(menuChoice != 8){
      system("clear");
      printMenu();
      printf("Please chose an option:");
      scanf("%d", &menuChoice);

      switch(menuChoice){
         case 1:
           printSelection(menuChoice);
           break;
         case 2:
           printSelection(menuChoice);
           break;
         case 3:
           printSelection(menuChoice);
           break;
         case 4:
           printSelection(menuChoice);
           break;
         case 5:
           printSelection(menuChoice);
           break;
         case 6:
           printSelection(menuChoice);
           break;
         case 7:
           printSelection(menuChoice);
         case 8:
          break;
      }
   }
   return 0;
}