#include <stdio.h>
#include "d_f_automaton.h"


void create_automaton(dfa *automaton, list *states, const char *inputs,
                      state *initial, list *transitions, list *finals) {
    automaton->states = states;
    automaton->final_states = finals;
    automaton->transitions = transitions;
    automaton->current_state = initial;
    struct node_single *iter = transitions->tail;
    while (iter != nullptr) {
        transition *tran = (transition *)iter->data;
        if (tran->current_state->transitions == nullptr) tran->current_state->transitions = new(sizeof(list));
        add(tran->current_state->transitions, tran);
        iter = iter->next;
    }
    automaton->symbols = inputs;
}

void destroy_automaton(dfa *automaton) {
    struct node_single *iter = automaton->states->tail;
    while (iter != nullptr) {
        state *s = (state*) iter;
        if (s->transitions != nullptr)
            //delete(s->transitions);
        iter = iter->next;
    }
    delete(automaton->states);
    delete(automaton->final_states);
    delete(automaton->transitions);
}

bool process(dfa *automaton, char symbol) {
    list *l = automaton->current_state->transitions;
    struct node_single *iter = l->tail;
    while (iter != nullptr) {
        transition *tran = (transition *)iter->data;
        if (tran->symbol == symbol) {
            automaton->current_state = tran->next_state;
            break;
        } else {
            iter = iter->next;
        }
    }
    return true;
}

bool transit(dfa *automaton, const char symbol) {
    size_t i = 0;
    while (automaton->symbols[i] != '\0') {
        if (symbol == automaton->symbols[i++]) return process(automaton, symbol);
    }
    return false;
}

bool evaluate(dfa *automaton, const char *string) {
    size_t i = 0;
    while (string[i] != '\0') {
        if (transit(automaton, string[i++])) continue;
        else return false;
    }
    return contains(automaton->final_states, automaton->current_state);
}
