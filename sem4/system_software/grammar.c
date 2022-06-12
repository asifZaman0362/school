#include <stdio.h>
#include <stdbool.h>

bool contains(const char *string, const char ch) {
	for (string; *string != '\0'; string++) {
		if (*string == ch) return true;
	}
	return false;
}

void extract_symbols(const char *code, char *terminals, char *nonterminals) {
	static int i = 0, j = 0;
	for (code; *code != '\0'; code++) {
		char ch = *code;
		if (ch >= 65 && ch <= 90) {
			if (!contains(nonterminals, ch)) nonterminals[i++] = ch;
		} else if (ch == '|' || ch == '#') continue;
		else if (ch == '-' && *(code + 1) == '>') code++;
		else if (!contains(terminals, ch)) terminals[j++] = ch;
	}
	terminals[j] = '\0'; nonterminals[i] = '\0';
}

int main() {
	char productions[10][30], terminals[100], nonterminals[100];
	printf("Enter production rules (# to represent null and $ to end input):");
	for (int i = 0; i < 10; i++) {
		printf(">> ");
		fgets(productions[i], 100, stdin);
		if (productions[i][0] == '$') break;
		else extract_symbols(productions[i], terminals, nonterminals);
		i++;
	}
	printf("Set of terminals: %s\n", terminals);
	printf("Set of terminals: %s\n", nonterminals);
	return 0;
}