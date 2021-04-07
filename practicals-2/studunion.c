#include <stdio.h>

union Student {
    char name[30];
    int age;
    int roll;
    int marks;
};

int main() {
    int n;
    printf("Enter the number of students : ");
    scanf("%d", &n);
    union Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Roll: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }
    for (int i = 0; i < n; i++) {
        printf("Name: %s", students[i].name);
        printf("Age: %d", students[i].age);
        printf("Roll: %d", students[i].roll);
        printf("Marks: %d", students[i].marks);
    }

    return 0;
}
