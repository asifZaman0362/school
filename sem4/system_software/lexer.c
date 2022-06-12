#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


#define FLAG_UNDEFINED	0
#define FLAG_OPERATOR	1
#define FLAG_OTHER		2

typedef unsigned int uint;


typedef enum {
    LITERAL, KEYWORD, IDENTIFIER, OPERATOR, ERROR
} token_type;

typedef struct {
    char lexeme[20];
    token_type type;
} token_t;


unsigned long hash_table_keywords[32];
unsigned long hash_table_operators[18];


void setup() {
    const char keywords[32][100] = {
            "auto", "double", "int", "struct", "break", "else", "long", "switch",
            "case", "enum", "register", "typedef", "char", "extern", "return", "union",
            "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
            "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"
    };
    const char compound_operators[18][3] = {
            "++", "--", "+=", "-=", "*=", "/=", "%=", "&&", "||", 
            "~=", "^=", "==", ">=", "<=", ">>", "<<", "|=", "&="
    };
    for (int i = 0; i < 32; i++) {
        hash_table_keywords[i] = compute_hash(keywords[i]);
        if (i < 18) hash_table_operators[i] = compute_hash(compound_operators[i]);
    }
}


bool is_operator(const char symbol) {
    return contains("(){}[]<>!=%*&:?/+-|", symbol);
}

bool is_compound_operator(const char *token) {
    unsigned long hash = compute_hash(token);
    for (int i = 0; i < 18; i++) {
        if (hash_table_operators[i] == hash) return true;
    } return false;
}

bool is_keyword(const char *token) {
    unsigned long hash = compute_hash(token);
    for (int i = 0; i < 32; i++) {
        if (hash_table_keywords[i] == hash) return true;
    } return false;
}

bool is_literal(const char *token) {
    bool flag = false; // flag for the decimal symbol
    for (const char *iter = token; *iter != '\0'; iter++) {
        if (*iter >= '0' && *iter <= '9' || (*iter == '.' && !flag)) {
            if (*iter == '.' && !flag) flag = true;
        } else return false;
    }
    return true;
}

bool is_identifier(const char *token) {
    bool flag = false;
    for (const char *iter = token; *iter != '\0'; iter++) {
        const char ch = *iter;
        if (!flag) {
            if (!((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 182) || ch == '_'))
                return false;
            else flag = true;
        } else {
            if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 182)
                || ch == '_' || (ch >= '0' && ch <= '9')) {
                continue;
            } else return false;
        }
    }
    return true;
}

void make_token(const char *string, token_t *token, const uint i) {
    if (i == 1) {
        if (is_operator(string[0])) {
            token->lexeme[0] = string[0];
            token->lexeme[1] = '\0';
            token->type = OPERATOR;
            return;
        }
    }
    if (is_compound_operator(string)) {
        strcpy(token->lexeme, string);
        token->type = OPERATOR;
    } else if (is_literal(string)) {
        strcpy(token->lexeme, string);
        token->type = LITERAL;
    } else if (is_keyword(string)) {
        strcpy(token->lexeme, string);
        token->type = KEYWORD;
    } else if (is_identifier(string)) {
        strcpy(token->lexeme, string);
        token->type = IDENTIFIER;
    } else token->type = ERROR;
}

uint tokenise(const char *code, token_t *tokenstream) {
    uint i = 0, j = 0, flag = FLAG_UNDEFINED;
    bool multiline_comment = false, singleline_comment = false;
    char token_builder[20];
    for (const char *iter = code; *iter != '\0'; iter++) {
        const char ch = *iter;
        if (singleline_comment) {
        	if (ch == '\n') singleline_comment = false;
        } else if (multiline_comment) {
        	if (ch == '*' && *(iter + 1) == '/') {
        		multiline_comment = false;
        		iter++;
        	}
        }
        else if (is_operator(ch)) {
        	if (ch == '/' && *(iter + 1) == '/') {
        		singleline_comment = true;
        		if (i > 0) {
                    token_builder[i] = '\0';
                    make_token(token_builder, &tokenstream[j++], i);
                    i = 0;
                } continue;
        	} else if (ch == '/' && *(iter + 1) == '*') {
        		multiline_comment = true;
        		if (i > 0) {
                    token_builder[i] = '\0';
                    make_token(token_builder, &tokenstream[j++], i);
                    i = 0;
                } continue;
        	}
            if (flag == FLAG_OPERATOR) token_builder[i++] = ch;
            else {
                if (i > 0) {
                    token_builder[i] = '\0';
                    make_token(token_builder, &tokenstream[j++], i);
                    i = 0;
                }
                token_builder[i++] = ch;
            }
            flag = FLAG_OPERATOR;
        } else if (contains(" \t\n;", ch)) {
            flag = FLAG_UNDEFINED;
            if (i > 0) {
                token_builder[i] = '\0';
                make_token(token_builder, &tokenstream[j++], i);
                i = 0;
            } else continue;
        } else {
            if (flag == FLAG_OPERATOR) {
                if (i > 0) {
                    token_builder[i] = '\0';
                    make_token(token_builder, &tokenstream[j++], i);
                    i = 0;
                }
                token_builder[i++] = ch;
            } else token_builder[i++] = ch;
            flag = FLAG_OTHER;
        }
    }
    if (i > 0) {
        token_builder[i] = '\0';
        make_token(token_builder, &tokenstream[j++], i);
    }
    return j;
}


int main(void) {
    setup();
    token_t tokenstream[100];
    char input_buffer[100];
    printf("Enter C code:\n");
    fgets(input_buffer, 100, stdin);
    uint j = tokenise(input_buffer, tokenstream);
    printf("Tokens formed:\n");
    for (int i = 0; i < j; i++) {
        printf("Token:\n");
        printf("\tlexeme: %s\n", tokenstream[i].lexeme);
        switch (tokenstream[i].type) {
            case LITERAL:
                printf("\ttype: LITERAL\n");
                break;
            case IDENTIFIER:
                printf("\ttype: IDENTIFIER\n");
                break;
            case KEYWORD:
                printf("\ttype: KEYWORD\n");
                break;
            case OPERATOR:
                printf("\ttype: OPERATOR\n");
                break;
            case ERROR:
                printf("\ttype: ERROR\n");
                break;
        }
    }
    return 0;
}