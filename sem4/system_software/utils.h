#ifndef COMPILER_UTILS
#define COMPILER_UTILS

#include <stdlib.h>

bool contains(const char *string, const char ch) {
    for (; *string != '\0'; string++) {
        if (*string == ch) return true;
    }
    return false;
}

void assert(int condition, const char *message) {
    if (condition) return;
    else {
        printf("Assertion failed: %s\n", message);
        exit(-1);
    }
}

unsigned long compute_hash(const char *string) {
    unsigned long hash = 0;
    for (const char *c = string; *c != '\0'; c++) {
        hash = hash * 31 + (int)*c;
    } return hash % 2147483647;
}

#endif