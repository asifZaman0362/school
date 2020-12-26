#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32_) || defined(_WIN64_)
#define clear() system("cls")
#endif
#ifdef linux
#define clear() system("clear")
#endif

int main() {
    const char* method = "string";
    clear();

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