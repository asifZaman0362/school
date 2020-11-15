#include "zio.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


void format(char* out, const char* format, ...) {
    va_list args;
    va_start(args, format);
    vsprintf(out, format, args);
}

#define bool int
#define true 1
#define false 0

void promptf(const char* msg, const char* fmt, ...) {

    va_list list;
    va_start(list, fmt);

    bool pflag = false;
    char p[100], m[200];
    int i = 0, j = 0;

    while(msg[i] != '\0') {
        if (msg[i] == '%' && msg[i+1] != '\0') {
            pflag = true;
        } else if (pflag) {
            p[j++] = msg[i];
        } else if (msg[i] == '%' && msg[i+1] == '%') {
            m[i++] = '%';
        } else {
            m[i] = msg[i];
        }
        i++;
    }

    m[i-j-1] = '\0';
    p[j] = '\0';

    printf("%s", m);

    i = 0;

    while(fmt[i] != '\0') {
        if (fmt[i] == 's') {
            char *ch = va_arg(list, char*);
            printf("%s", j > 0 ? p : ">> ");
            fgets(ch, 100, stdin);
            ch[strcspn(ch, "\n")] = 0;
        } else if (fmt[i] == 'i') {
            int *in = va_arg(list, int*);
            printf("%s", j > 0 ? p : ">> ");
            scanf_s("%d", in);
        } else if (fmt[i] == 'f') {
            float *fl = va_arg(list, float*);
            printf("%s", j > 0 ? p : ">> ");
            scanf_s("%f", fl);
        } else if (fmt[i] == 'd') {
            double *db = va_arg(list, double*);
            printf("%s", j > 0 ? p : ">> ");
            scanf_s("%lf", db);
        } else if (fmt[i] == 'c') {
            char *c = va_arg(list, char*);
            printf("%s", j > 0 ? p : ">> ");
            scanf_s(" %c", c);
        }
        i++;
    }

    va_end(list);

}