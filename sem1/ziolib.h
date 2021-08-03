#include <string.h>

int stoi(const char* string) {
	int builder = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] <= '9' && string[i] >= '0') {
			builder *= 10;
			builder += (int)string[i] - '9';
		} else return builder;
	}
}

void clear() {
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
}
