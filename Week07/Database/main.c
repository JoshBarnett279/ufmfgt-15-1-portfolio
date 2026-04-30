#include <stdio.h>

#define LEN 50
#define N   3  // Number of students

typedef struct {
    char first_name[LEN];
    char initial;
    char second_name[LEN];
} Person_Name;

typedef struct {
    Person_Name name;
    int id_number;
    int age;
    char module_code[LEN];
} Student;

Student students[N];


void readStudent(Student *s) {

    printf("Enter first name: ");
    scanf("%s", s->name.first_name);

    printf("Enter initial: ");
    scanf(" %c", &s->name.initial);

    printf("Enter second name: ");
    scanf("%s", s->name.second_name);

    printf("Enter ID number: ");
    scanf("%d", &s->id_number);

    printf("Enter age: ");
    scanf("%d", &s->age);

    printf("Enter module code: ");
    scanf("%s", s->module_code);
}

void displayStudent(Student s) {

    printf("Name: %s %c %s\n", s.name.first_name, s.name.initial, s.name.second_name);
    printf("ID: %d\n", s.id_number);
    printf("Age: %d\n", s.age);
    printf("Module: %s\n", s.module_code);
}

// Function to display all students
void displayAll(Student students[], int size) {

    for (int i = 0; i < size; i++) {
        printf("----- Student %d -----\n", i + 1);
        displayStudent(students[i]);
    }
}

int main() {

    for (int i = 0; i < N; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    displayAll(students, N);

    return 0;
}