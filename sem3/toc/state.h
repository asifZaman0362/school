//
// Created by asif on 2/20/22.
//

#ifndef AUTOMATA_STATE_H
#define AUTOMATA_STATE_H

#include "utils.h"

typedef struct state_transition {
    struct automaton_state *current_state;
    struct automaton_state *next_state;
    char symbol;
} transition;

typedef struct automaton_state {
    unsigned long id;
    list *transitions;
} state;

#endif //AUTOMATA_STATE_H
