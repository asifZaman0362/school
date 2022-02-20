//
// Created by asif on 2/20/22.
//

#include "d_f_automaton.h"
#include <stdio.h>

int main(void) {
    dfa automaton;
    state q0 = { 0, nullptr }, q1 = { 1, nullptr };
    const char *symbols = "01";
    transition t1 = { &q0, &q1, '0' }, t2 = { &q1, &q0, '0' };
    transition t3 = { &q0, &q0, '1' }, t4 = { &q1, &q1, '1' };
    list *states = new(sizeof(list));
    list *transitions = new(sizeof(list));
    list *finals = new(sizeof(list));
    add(states, &q0);
    add(states, &q1);
    add(finals, &q0);
    add(transitions, &t1);
    add(transitions, &t2);
    add(transitions, &t3);
    add(transitions, &t4);
    create_automaton(&automaton, states, symbols, &q0, transitions, finals);
    printf("The string is %s", (evaluate(&automaton, "0101") == true ? "accepted." : "not accepted."));
    destroy_automaton(&automaton);
    get_total_memory();
}