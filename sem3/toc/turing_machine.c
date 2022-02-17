#include <stdio.h>

typedef struct StateNode {
    int state;
    struct StateNode* next;
};

typedef struct turing_machine {
    struct StateNode* state_list;
    char* terminals;
    char* tape_symbols;
    struct Transition* transitions;
    struct StateNode* init_state;
    struct StateNode* final_states;
};

typedef struct Transition {
    struct StateNode* current;
    struct StateNode* next;
};

int main (void) {
    return 0;
}
