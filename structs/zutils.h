#ifndef _ZUTILS_H_
#define _ZUTILS_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned char byte;

#if defined(WIN_32) || defined(WIN_64)
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

#define BLACK       "\x1B[30m"
#define RED         "\x1B[31m"
#define GREEN       "\x1B[32m"
#define YELLOW      "\x1B[33m"
#define BLUE        "\x1B[34m"
#define MAGENTA     "\x1B[35m"
#define WHITE       "\x1B[37m"
#define BLACK_B     "\x1B[90m"
#define RED_B       "\x1B[91m"
#define GREEN_B     "\x1B[92m"
#define YELLOW_B    "\x1B[93m"
#define BLUE_B      "\x1B[94m"
#define MAGENTA_B   "\x1B[95m"
#define WHITE_B     "\x1B[97m"
#define RESET       "\033[0m"

#define CASUAL 0
#define TERMINAL 1
#define SERIOUS 2


void log_err(const char* mssg, ushort severity) {
    printf("\n\t%sError: %s\n\n", RED, mssg);
    printf("%s", RESET);
    if (severity >= TERMINAL) exit(-1);
}

void log_mssg(const char* mssg) {
    printf("\n\t%sDebug Message: %s\n\n", WHITE_B, mssg);
    printf("%s", RESET);
}

void log_warn(const char* mssg) {
    printf("\n\t%sWarning: %s\n\n", YELLOW, mssg);
    printf("%s", RESET);
}

void log_success(const char* mssg) {
    printf("\n\t%sResult: %s\n\n", GREEN, mssg);
    printf("%s", RESET);
}

#endif
