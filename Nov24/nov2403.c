#include <stdio.h>

int main() {
    char c;
    printf("Enter a single alphabet : ");
    scanf("%c", &c);
    if (c >= 'a' && c <= 'z') printf("'%c' is a lowercase letter.\n", c);
    else if (c >= 'A' && c <= 'Z') printf("'%c' is an uppercase letter.\n", c);
    else printf("'%c' is not a letter at all! Try again.\n", c);
    return 0;
}
