#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;              
    char firstName[10];  
    char lastName[10];   
    int scores[5];
    float total;
    char grade[2];
} Student;

typedef struct {
  float a;
  float b;
  float c;
  float d;
} Mapping;

int compareById(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    // Compare total grades
    if (studentA->id < studentB->id) return -1;  // For descending order
    if (studentA->id > studentB->id) return 1; // For ascending order
    return 0; // Equal
}

int compareByTotal(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    // Compare total grades
    if (studentA->total < studentB->total) return 1;  // For descending order
    if (studentA->total > studentB->total) return -1; // For ascending order
    return 0; // Equal
}

int compareByExam(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    
    // Compare total grades
    if (studentA->scores[4] < studentB->scores[4]) return 1;  // For descending order
    if (studentA->scores[4] > studentB->scores[4]) return -1; // For ascending order
    return 0; // Equal
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

float calculateTotal(int a1, int a2, int a3, int m, int e){
   double assignmentAverage = (a1+a2+a3)/3.0;

   float assignmentsGrade = (assignmentAverage/40.0)*25.0;

   float midtermGrade = (m/25.0)*25.0;

   float examGrade = (e/40.0)*50.0;

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
        strcpy(students[a].firstName, token); // Copy first name
    }

    token = strtok(NULL, "|");
    if (token != NULL) {
        strcpy(students[a].lastName, token); // Copy last name
    }

    for (int i = 0; i < 5; i++) {   
        token = strtok(NULL, "|");
        if (token != NULL) {
            students[a].scores[i] = atoi(token); // Assign score
        }
    }

    float tg = calculateTotal(students[a].scores[0],students[a].scores[1],students[a].scores[2],students[a].scores[3],students[a].scores[4]);

    students[a].total = tg;

    students[a].grade[0] = getLetterGrade(tg,map);
    students[a].grade[1] = '\0';

    a++;
   }

   qsort(students,a,sizeof(Student), compareById);

   fclose(file_ptr);
}


int countStudents(){
   char line[256];

   FILE *file_ptr = fopen("students.txt", "r");

   int a = 0;

   while (fgets(line, sizeof(line), file_ptr) != NULL){
    a++;
   }

   fclose(file_ptr);

   return a;
}

void printSheet(Student *students, int studentCount){
  printf("ID    Last       First      A1  A2  A3  Midterm  Exam   Total   Grade\n");
  printf("--    ----       -----      --  --  --  -------  ----   -----   -----\n");
  for(int i = 0; i < studentCount;i++){
    printf("%-6d %-10s %-10s", students[i].id, students[i].firstName, students[i].lastName);
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

void displayHistogram(Student *students){
  int intSize[20];
  int length;
  length = sizeof(intSize) / sizeof(students);

  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int f = 0;

  for(int i = 0; i < length; i++){
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

void setMapping(Mapping *map,float a, float b, float c, float d){
  map->a = a;
  map->b = b;
  map->c = c;
  map->d = d;
}

void printColumnSort(Student *students,int numberOfStudents){
  printf("Column Options\n");
  printf("-----------\n");
  printf("1. Student ID\n");
  printf("2. Last Name\n");
  printf("3. Exam\n");
  printf("4. Total\n");

  int menuChoice = 0;
  printf("\nPlease chose an option:");
  scanf("%d", &menuChoice);

  switch(menuChoice){
         case 1:
           qsort(students,numberOfStudents,sizeof(Student), compareById);
           printf("You sorted by ID succesfully");
           break;
         case 2:
           printf("You sorted by last name succesfully");
           break;
         case 3:
           qsort(students,numberOfStudents,sizeof(Student), compareByExam);
           printf("You sorted by exam grade succesfully");
           break;
         case 4:
           qsort(students,numberOfStudents,sizeof(Student), compareByTotal);
           printf("You sorted by total grade succesfully");
           break;
      }
}

void changeLastName(Student *students, int studentCount, int id, char *newLastName){
  for(int i = 0; i < studentCount;i++){
    if(students[i].id == id){
      strcpy(students[i].lastName,newLastName);
    }
  }
}

void changeExamGrade(Student *students, int studentCount, int id, int newGrade){
  for(int i = 0; i < studentCount;i++){
    if(students[i].id == id){
      students[i].scores[4] = newGrade;
      students[i].total = calculateTotal(students[i].scores[0],students[i].scores[1],students[i].scores[2],students[i].scores[3],students[i].scores[4]);
    }
  }
}

int main() {
   int studentCount = countStudents();

   Mapping *map = (Mapping *) malloc(sizeof(Mapping) * 1);
   setMapping(map,80,70,60,50);

   Student *students_array = (Student *) malloc(sizeof(Student) * studentCount);

   readFile(students_array,map);

   int menuChoice = 0;
   int id;
   while(menuChoice != 8){
      system("clear");
      printMenu();
      printf("Please chose an option:");
      scanf("%d", &menuChoice);

      switch(menuChoice){
         case 1:
           system("clear");
           printSheet(students_array,studentCount);
           proceed();
           break;
         case 2:
           system("clear");
           displayHistogram(students_array);
           proceed();
           break;
         case 3:
           system("clear");
           printColumnSort(students_array,studentCount);
           proceed();
           break;
         case 4:
           system("clear");
           printSheet(students_array,studentCount);
           char newLastName[20];
           printf("\nEnter Student ID:");
           scanf("%d",&id);
           printf("\nEnter Updated Last name:");
           scanf("%s",newLastName);
           changeLastName(students_array,studentCount,id,newLastName);
           proceed();
           break;
         case 5:
           system("clear");
           printSheet(students_array,studentCount);
           int newGrade;
           printf("\nEnter Student ID:");
           scanf("%d",&id);
           printf("\nEnter Updated Last name:");
           scanf("%d",&newGrade);
           changeExamGrade(students_array,studentCount,id,newGrade);
           proceed();
           break;
         case 6:
           system("clear");
           printf("Current Mapping:\n");
           printf(" A: >= %.2f\n",map->a);
           printf(" B: >= %.2f\n",map->b);
           printf(" C: >= %.2f\n",map->c);
           printf(" D: >= %.2f\n",map->d);
           printf(" F:  < %.2f\n",map->d);

           float baselineA;
           float baselineB;
           float baselineC;
           float baselineD;

           printf("Enter new A baseline:");
           scanf("%f",&baselineA);
           printf("Enter new B baseline:");
           scanf("%f",&baselineB);
           printf("Enter new C baseline:");
           scanf("%f",&baselineC);
           printf("Enter new D baseline:");
           scanf("%f",&baselineD);

           setMapping(map,baselineA,baselineB,baselineC,baselineD);

           printf("New Mapping:");
           printf(" A: >= %.2f\n",map->a);
           printf(" B: >= %.2f\n",map->b);
           printf(" C: >= %.2f\n",map->c);
           printf(" D: >= %.2f\n",map->d);
           printf(" F:  < %.2f\n",map->d);

           proceed();
           
           break;
         case 7:
           system("clear");
           break;
         case 8:
          break;
      }
   }
   return 0;
}