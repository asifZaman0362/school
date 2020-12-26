#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* method = "string";

    if (method == "integer") {
        int num, orig, rev = 0;
        printf("Enter a number : ");
        scanf("%d", &num);
        orig = num;
        if (num < 0) num *= -1;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        if (rev == orig) printf("%d is a pallindrome.\n", orig);
    }
    // Alternatively, using strings
    else {
        char str[100];
        int i = 0, j = 0, isPallindrome = 1;
        printf("Enter a number / word : ");
        scanf("%s", str);
        while (str[i] != '\0') i++;
        while (i-- >= 0) if (str[i] != str[j++]) isPallindrome = 0;
        if (isPallindrome) printf("%s is a pallindrome.\n", str);
        else printf("%s is not a pallindrome.\n", str);
    }

    return 0;
}