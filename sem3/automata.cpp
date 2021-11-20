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
    State Q[4];
    Q[0].transitions.push_back(Transition{"a", &Q[1]});
    Q[0].transitions.push_back(Transition{"bc", &Q[0]});
    Q[1].transitions.push_back(Transition{"c", &Q[0]});
    Q[1].transitions.push_back(Transition{"a", &Q[1]});
    Q[1].transitions.push_back(Transition{"b", &Q[2]});
    Q[2].transitions.push_back(Transition{"b", &Q[0]});
    Q[2].transitions.push_back(Transition{"a", &Q[1]});
    Q[2].transitions.push_back(Transition{"c", &Q[3]});
    Q[3].transitions.push_back(Transition{"a", &Q[1]});
    Q[3].transitions.push_back(Transition{"bc", &Q[0]});
    bool acceptsFirst = Evaluate(&Q[0], "abc") == &Q[3];
    bool acceptsSecond = Evaluate(&Q[0], "abbcabbc") == &Q[3];
    std::cout << acceptsFirst << ";" << acceptsSecond << std::endl;
    return 0;
}
