#include <stdio.h>

struct student {
    char name[20];
    int roll;
    int marks;
    int class;
} s;

int main() {
    printf("Enter name: ");
    scanf("%[A-Za-z ]s", s.name);
    printf("Entet roll no: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%d", &s.marks);
    printf("Enter class: ");
    scanf("%d", &s.class);
    printf("\nStudent Details-------\n");
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("Marks: %d\n", s.marks);
    printf("Class: %d\n", s.class);
    return 0;
}
