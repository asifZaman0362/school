//
// Created by asif on 2/20/22.
//

#ifndef SCHOOL_AUTOMATON_H
#define SCHOOL_AUTOMATON_H

#include "utils.h"
#include "state.h"

typedef struct deterministic_finite_automaton {
    list *states;
    list *final_states;
    list *transitions;
    state *current_state;
    const char *symbols;
} dfa;

void create_automaton(dfa*, list*, const char*, state*, list*, list*);
void destroy_automaton(dfa*);
bool transit(dfa*, const char);
bool evaluate(dfa*, const char*);

#endif //SCHOOL_AUTOMATON_H
