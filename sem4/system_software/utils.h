#ifndef COMPILER_UTILS
#define COMPILER_UTILS

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

bool contains(const char *string, const char ch) {
    for (; *string != '\0'; string++) {
        if (*string == ch) return true;
    }
    return false;
}

void assert(int condition, const char *format, ...) {
    if (condition) return;
    else {
        va_list arglist;
        va_start(arglist, format);
        printf("Assertion error: ");
        printf(format, arglist);
        va_end(arglist);
        printf("\n");
        exit(-1);
    }
}

unsigned long compute_hash(const char *string) {
    unsigned long hash = 0;
    for (const char *c = string; *c != '\0'; c++) {
        hash = hash * 31 + (int) *c;
    } return hash % 2147483647;
}

unsigned long compute_hash_n(const char *string, const int n) {
    unsigned long hash = 0;
    for (int i = 0; i < n && string[i] != '\0'; i++) {
        hash = hash * 31 + (int) string[i];
    } return hash % 2147483647;
}

bool is_alpha_(const char ch) {
    return (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 95;
}

bool is_digit(const char ch) {
    return (ch >= 48 && ch <= 57);
}

bool is_alnum_(const char ch) {
    return is_alpha_(ch) || is_digit(ch);
}

#endif