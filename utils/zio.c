#include "zio.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


void format(char* out, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsprintf(out, format, args);
}

void zgetch() {
    printf("/nPress any key to continue...");
    getchar();
}