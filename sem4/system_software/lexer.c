#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


#define FLAG_UNDEFINED  0
#define FLAG_OPERATOR   1
#define FLAG_OTHER      2

#define MAX_TOKEN_SIZE  30


typedef unsigned int uint;
typedef unsigned long ulong;

typedef enum {
    LITERAL, KEYWORD, IDENTIFIER, OPERATOR, ERROR, STRING, CHARACTER
} token_type;

typedef struct {
    char lexeme[20];
    token_type type;
} token_t;


ulong hash_table_keywords[32];
ulong hash_table_2_keywords[32];
ulong hash_table_operators[19];
ulong hash_table_2_operators[19];


void setup() {
    const char keywords[32][100] = {
            "auto", "double", "int", "struct", "break", "else", "long", "switch",
            "case", "enum", "register", "typedef", "char", "extern", "return", "union",
            "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
            "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"
    };
    const char compound_operators[19][4] = {
            "++", "--", "+=", "-=", "*=", "/=", "%=", "&&", "||",
            "^=", "==", ">=", "<=", ">>", "<<", "|=", "&=", ">>=", "<<="
    };
    for (int i = 0; i < 32; i++) {
        hash_table_keywords[i] = compute_hash(keywords[i]);
        hash_table_2_keywords[i] = compute_hash2(keywords[i]);
        if (i < 19) {
            hash_table_operators[i] = compute_hash(compound_operators[i]);
            hash_table_2_operators[i] = compute_hash2(compound_operators[i]);
        }
    }
}


bool is_operator(const char symbol) {
    return contains("(){}[]<>!=%*&:?/+-|,;", symbol);
}

bool is_whitespace(const char symbol) {
    return symbol == 32 || symbol == 10 || symbol == 9;
}

bool is_compound_operator(const char *token, const int n) {
    unsigned long hash = compute_hash_n(token, n);
    unsigned long hash2 = compute_hash2_n(token, n);
    for (int i = 0; i < 19; i++) {
        if (hash_table_operators[i] == hash && hash_table_2_operators[i] == hash2) return true;
    } return false;
}

bool is_keyword(const char *token) {
    unsigned long hash = compute_hash(token);
    unsigned long hash2 = compute_hash2(token);
    for (int i = 0; i < 32; i++) {
        if (hash_table_keywords[i] == hash && hash_table_2_keywords[i] == hash2) return true;
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
            if (!is_alpha_(ch)) return false;
            else flag = true;
        } else {
            if (is_alnum_(ch)) continue;
            else return false;
        }
    }
    return true;
}

void create_token(char *lexeme, token_t *stream, ulong *lexeme_length, ulong *stream_length, bool operator) {
    if (*lexeme_length == 0) return;
    lexeme[*lexeme_length] = '\0';
    if (operator) {
        if (*lexeme_length == 1) {
            stream[*stream_length].type = OPERATOR;
            stream[*stream_length].lexeme[0] = lexeme[0];
            stream[*stream_length].lexeme[1] = '\0';
            *stream_length += 1;
            *lexeme_length = 0;
            return;
        } else {
            // TODO: feels kinda fishy. check again [apparently not :)]
            ulong i = 0;
            while (i < *lexeme_length) {
                if (i == *lexeme_length - 1) {
                    stream[*stream_length].type = OPERATOR;
                    stream[*stream_length].lexeme[0] = lexeme[i];
                    stream[*stream_length].lexeme[1] = '\0';
                    *stream_length += 1;
                    *lexeme_length = 0;
                    return;
                }
                ulong j = *lexeme_length;
                while (!is_compound_operator(lexeme + i, j - i) && j > i) j--;
                if (j == i) {
                    stream[*stream_length].type = OPERATOR;
                    stream[*stream_length].lexeme[0] = lexeme[i];
                    stream[*stream_length].lexeme[1] = '\0';
                    *stream_length += 1;
                    i++;
                } else {
                    strncpy(stream[*stream_length].lexeme, lexeme + i, j);
                    stream[*stream_length].lexeme[j] = '\0';
                    stream[*stream_length].type = OPERATOR;
                    *stream_length += 1;
                    i = j;
                }
            }
        }
    }
    else if (is_literal(lexeme)) {
        strcpy(stream[*stream_length].lexeme, lexeme);
        stream[*stream_length].type = LITERAL;
        *stream_length += 1;
        *lexeme_length = 0;
    } else if (is_keyword(lexeme)) {
        strcpy(stream[*stream_length].lexeme, lexeme);
        stream[*stream_length].type = KEYWORD;
        *stream_length += 1;
        *lexeme_length = 0;
    } else if (is_identifier(lexeme)) {
        strcpy(stream[*stream_length].lexeme, lexeme);
        stream[*stream_length].type = IDENTIFIER;
        *stream_length += 1;
        *lexeme_length = 0;
    } else {
        strcpy(stream[*stream_length].lexeme, lexeme);
        stream[*stream_length].type = ERROR;
        *stream_length += 1;
        *lexeme_length = 0;
    }
    *lexeme_length = 0;
}

const char* find_next_linebreak(const char *string) {
    for (; *string != '\n'; string++) {
        if (*string == '\0') return string;
    }
    return string;
}

const char* find_multiline_comment_end(const char *string) {
    for (; *string != '\0'; string++) {
        if (*string == '*' && *(string + 1) == '/') return string + 1;
    }
    return string;
}

const char* scan_string_literal(const char *string, char *parsed_lexeme, ulong *lexeme_length) {
    bool escape = false;
    ulong i = 0;
    for (; *string != '\0'; string++) {
        const char ch = *string;
        if (escape) {
            switch (ch) {
                case 'n':
                    parsed_lexeme[i++] = '\n';
                    break;
                case 't':
                    parsed_lexeme[i++] = '\t';
                    break;
                case 'a':
                    parsed_lexeme[i++] = '\a';
                    break;
                default:
                    parsed_lexeme[i++] = ch;
            }
            escape = false;
        } else if (ch == '\\') {
            escape = true;
        } else if (ch == '"') {
            parsed_lexeme[i] = '\0';
            *lexeme_length = i;
            return string + 1;
        } else parsed_lexeme[i++] = ch;
    }
    assert(*string != '\0', "Error: couldn't find ending quote for string literal at: %lu", i);
    *lexeme_length = i;
    return string;
}

const char* scan_character_literal(const char *string, char *parsed_lexeme, ulong *lexeme_length) {
    bool escape = false;
    ulong i = 0;
    for (; *string != '\0'; string++) {
        const char ch = *string;
        if (escape) {
            switch (ch) {
                case 'n':
                    parsed_lexeme[i++] = '\n';
                    break;
                case 't':
                    parsed_lexeme[i++] = '\t';
                    break;
                case 'a':
                    parsed_lexeme[i++] = '\a';
                    break;
                default:
                    parsed_lexeme[i++] = ch;
            }
            escape = false;
        } else if (ch == '\\') {
            escape = true;
        } else if (ch == '\'') {
            parsed_lexeme[i] = '\0';
            assert(i == 1, "Error: not a valid character");
            return string + 1;
        } else parsed_lexeme[i++] = ch;
    }
    assert(*string != '\0', "Error: couldn't find ending quote for string literal");
    *lexeme_length = i;
    return string;
}


ulong lex(const char *code, token_t *token_stream) {
    char lexeme[MAX_TOKEN_SIZE];
    ulong lexeme_length = 0, stream_length = 0;
    ushort flag = FLAG_UNDEFINED;
    for (const char *iter = code; *iter != '\0'; iter++) {
        char ch = *iter, lookahead = *(iter + 1);
        if (ch == '/' && lookahead == '*') {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
            iter = find_multiline_comment_end(iter);
        } else if (ch == '/' && lookahead == '/') {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
            iter = find_next_linebreak(iter);
        } else if (ch == '"') {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
            iter = scan_string_literal(iter + 1, lexeme, &lexeme_length);
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, false);
            token_stream[stream_length - 1].type = STRING;
        } else if (ch == '\'') {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
            iter = scan_character_literal(iter + 1, lexeme, &lexeme_length);
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, false);
            token_stream[stream_length - 1].type = CHARACTER;
        } else if (is_operator(ch)) {
            if (flag == FLAG_OTHER)
                create_token(lexeme, token_stream, &lexeme_length, &stream_length, false);
            lexeme[lexeme_length++] = ch;
            flag = FLAG_OPERATOR;
        } else if (is_whitespace(ch)) {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
            flag = FLAG_UNDEFINED;
        } else {
            if (flag == FLAG_OPERATOR)
                create_token(lexeme, token_stream, &lexeme_length, &stream_length, true);
            lexeme[lexeme_length++] = ch;
            flag = FLAG_OTHER;
        }
        if (lookahead == '\0' || ch == '\0') {
            create_token(lexeme, token_stream, &lexeme_length, &stream_length, flag == FLAG_OPERATOR);
        }
    }
    return stream_length;
}


int main(void) {
    setup();
    token_t tokenstream[100];
    char input_buffer[100];
    printf("Enter C code:\n");
    fgets(input_buffer, 100, stdin);
    ulong j = lex(input_buffer, tokenstream);
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
            case CHARACTER:
                printf("\ttype: CHARACTER LITERAL\n");
                break;
            case STRING:
                printf("\ttype: STRING LITERAL\n");
                break;
            case ERROR:
                printf("\ttype: ERROR\n");
                break;
        }
    }
    return 0;
}