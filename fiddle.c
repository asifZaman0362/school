#include <stdio.h>
#include <stdlib.h>

void main(int argv, const char** argc) {

	if (argv > 1) {
		for (int i = 0; i < argv; i++) {
			printf("%s", argc[i]);
		}
	}

    #ifdef linux
    system("clear");
    #endif
    #ifdef _WIN32
    system("cls");
    #endif

	return;
}
