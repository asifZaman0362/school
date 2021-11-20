#include <iostream>
#include <vector>
#include <string>

struct State;

struct Transition {
    std::string input;
    State* next;
};

struct State {
    std::vector<Transition> transitions;
};

State* DetermineNext(State* present, char input) {
    for (auto& transition : present->transitions) {
        for (char c : transition.input) {
            if (c == input) {
                return transition.next;
            }
        }
    }
    return nullptr;
}

State* Evaluate(State* initial, std::string str) {
    State* st = initial;
    for (char c : str) {
        st = DetermineNext(st, c);
    }
    return st;
}

int main() {
    State *q0 = new State{}, *q1 = new State{}, *q2 = new State{}, *q3 = new State{};
    State *qf = q3;
    q0->transitions.push_back(Transition{"a", q1});
    q0->transitions.push_back(Transition{"bc", q0});
    q1->transitions.push_back(Transition{"c", q0});
    q1->transitions.push_back(Transition{"a", q1});
    q1->transitions.push_back(Transition{"b", q2});
    q2->transitions.push_back(Transition{"b", q0});
    q2->transitions.push_back(Transition{"a", q1});
    q2->transitions.push_back(Transition{"c", q3});
    q3->transitions.push_back(Transition{"a", q1});
    q3->transitions.push_back(Transition{"bc", q0});
    bool acceptsFirst = Evaluate(q0, "abc") == qf;
    bool acceptsSecond = Evaluate(q0, "abbcabc") == qf;
    std::cout << acceptsFirst << ";" << acceptsSecond << std::endl;
    return 0;
}
