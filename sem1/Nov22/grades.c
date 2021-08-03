#include <stdio.h>
#include <stdlib.h>


const char* getGrade(int marks) {

    if (marks >= 95)        return "A+";
    else if (marks >= 85)   return "A";
    else if (marks >= 75)   return "B+";
    else if (marks >= 70)   return "B";
    else if (marks >= 65)   return "C";
    else if (marks >= 55)   return "D";
    else if (marks >= 45)   return "E";
    else                    return "F";

}

int main() {

    int marks = 0;
    char grade;

    //system("clear");
    while(1) {
        printf("Enter the marks obtained by the student >> ");
        scanf("%d", &marks);
        if (marks >= 0 && marks <= 100) break;
        else printf("Marks can only be from 0 to 100!\nTry again...");
    }
    
    printf("Student's grade : %s\n", getGrade(marks));

    return 0;

}