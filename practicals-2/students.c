#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    char name[50];
    unsigned short age;
    unsigned short class;
    unsigned short roll;
    unsigned short marks;
};

struct Student* GetStudent() {
    struct Student* s = malloc(sizeof(struct Student));
    
    printf("Enter student details: \n");
    printf("Name  : ");
    char c;
    scanf("%c", &c);
    fgets(s->name, 50, stdin);
    printf("Age   : ");
    scanf("%hu", &s->age);
    printf("Class : ");
    scanf("%hu", &s->class);
    printf("Roll  : ");
    scanf("%hu", &s->roll);
    printf("Marks : ");
    scanf("%hu", &s->marks);

    return s;
}

void PrintStudentInfo(struct Student s) {
    printf("\n\nStudent Details:\n---------------------------\n");
    printf("  Name  : %s\n", s.name);
    printf("  Age   : %hu\n", s.age);
    printf("  Class : %hu\n", s.class);
    printf("  Roll  : %hu\n", s.roll);
    printf("  Marks : %hu\n", s.marks);
}

int main() {
    struct Student** students;
    int n;
    printf("Enter the number of students : ");
    scanf("%d", &n);
    students = (struct Student**) malloc(sizeof(struct Student*)*n);
    printf("Enter student information :\n");
    for (int i = 0; i < n; i++) {
        students[i] = GetStudent();
    }
    printf("\n\n\nListing all students:\n");
    for (int i = 0; i < n; i++) PrintStudentInfo(*students[i]);
    for (int i = 0; i < n; i++) free(students[i]);
    free(students);
}
