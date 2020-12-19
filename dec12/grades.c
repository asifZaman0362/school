#include <stdio.h>
#include <stdlib.h>


#if defined(_WIN32_) || defined(_WIN64_)
#define clear() system("cls")
#endif
#ifdef linux
#define clear() system("clear")
#endif


const char* getGrade(int marks) {

    switch (marks / 5) {
		case 20:
        case 19:
            return "A+";
        case 18:
            return "A";
        case 17:
            return "B+";
        case 16:
            return "B";
        case 15:
            return "C+";
        case 14:
            return "C";
        case 13:
            return "D+";
        case 12:
            return "E+";
        case 11:
        case 10:
            return "E";
        default:
            return "F";
    }

    return "F";

}

int main() {

    int marks = 0;
    char grade;

    clear();
    while(1) {
        printf("Enter the marks obtained by the student >> ");
        scanf("%d", &marks);
        if (marks >= 0 && marks <= 100) break;
        else printf("Marks can only be from 0 to 100!\nTry again...");
    }
    
    printf("Student's grade : %s\n", getGrade(marks));

    return 0;

}