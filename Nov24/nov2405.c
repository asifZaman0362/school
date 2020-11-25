#include <stdio.h>

int main() {
    char c;
    printf("Enter an alphabet : ");
    scanf("%c", &c);
    if (c >= 'A' && c <= 'Z') {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') printf("'%c' is a vowel.\n", c);
        else printf("'%c' is a consonant.\n", c);
    } else if (c >= 'a' && c <= 'z') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') printf("'%c' is a vowel.\n", c);
        else printf("'%c' is a consonant.\n", c);
    } else printf("'%c' is not an alphabet! Try again.\n", c);
    return 0;
}
