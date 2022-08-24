#ifndef ZLIBC_STDINC_H
#define ZLIBC_STDINC_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void prompt(const char *message, char *input, char *format, ...) {
    printf("%s", message);
    va_list arglist;
    va_start(arglist, format);
    vscanf(format, arglist);
    va_end(arglist);
}

#if defined(WIN_32) || defined(WIN_64)
#define clrscr() system("clrscr");
#else
#define clrscr() system("clear");
#endif

void split_string(const char *string, const char delimiter, char *list[100]) {
    size_t size = 0, count = 0;
    const char *iter = string;
    for (; *iter != '\0'; iter++) {
        if (*iter == delimiter) {
            const char *last = iter - size - 1;
            strncpy(list[count++], last, size - 1);
            size = 0;
        } else size++;
    }
    if (size != 0) // buffer has remaining characters
        strncpy(list[count++], iter - size - 1, size - 1);
}

void join_strings(const char *list[100], const char *joiner, char *dest, size_t n) {
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        for (const char *iter = list[i]; *iter != '\0'; iter++) 
            dest[count++] = *iter;
        for (const char *iter = joiner; *iter != '\0'; iter++)
            dest[count++] = *iter;
    }    
    dest[count] = '\0';
}
    

#endif
