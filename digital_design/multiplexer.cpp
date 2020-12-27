#include <iostream>
#include "logic_gates.hpp"


template <unsigned short N> struct pow2 {
    enum { val = 2*pow2<N-1>::val };
};

template<> struct pow2<0> {
    enum { val = 1 };
};


template <int N>
class Multiplexer {
private:
    const unsigned short size = pow2<N>::val;
    bool inputs[size];
    bool selection[N];
    bool output;
public:
    Multiplexer() {
        for (int i = 0; i < size; i++) inputs[i] = true;
    }
    bool SetInput(int n, bool _switch) {
        if (n >= size) return false;
        else return (inputs[n] = _switch) || true;
    }
    bool SetSelection(int n, bool _switch) {
        if (n >= N) return false;
        else return (selection[n] = _switch) || true;
    }
    bool Output() {
        bool ret = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2 * (i + 1); j++) {

            }
        }
    }
    void Print() {
        for (int i = 0; i < size; i++) std::cout << i << ": " << inputs[i] << std::endl;
    }
};

int main() {
    int x = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << x++ << std::endl;
        }
    }
    return 0;
}