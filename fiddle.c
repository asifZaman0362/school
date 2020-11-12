#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


void format(char* out, const char* format, ...) {
    char buffer[200];
    va_list list;
    va_start(list, format);
    vsprintf(buffer, format, list);
    va_end(list);
    strcpy(out, buffer);
}

void main() {

    char str[200];
    format(str, "Hi my name is %s and I am %d y.o.", "Asif", 20);
    printf("\n%s\n\n", str);
    getc(stdin);

    return;

}
