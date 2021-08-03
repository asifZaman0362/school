#include <stdio.h>

void main() {
    char c;
    printf("Enter a character >> ");
    scanf("%c", &c);
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) printf("\'%c\' is an alphabet.\n", c);
    else if (c >= '0' && c <= '9') printf("\'%c\' is a number.\n", c);
    else printf("\'%c\' is a special character.\n", c);
}