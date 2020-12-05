#pragma once
#include "logic_gates.hpp"


namespace tst::dd {
    namespace ALU {

        inline int pow2 (int n) {
            int sum = 1;
            for (int i = 0; i < n; i++) sum = sum * 2;
            return sum;
        }

        struct vec {
            bool a, b;
            vec(bool a, bool b) : a(a), b(b) {}
        };

        struct byte {
            bool bits[8] = { 0,0,0,0,0,0,0,0 };
            byte() {}
            byte(bool[]);
            int Decimal();
        };

        vec AddBits(bool a, bool b, bool c);

        byte AddBytes(byte a, byte b);

        vec SubtractBits(bool a, bool b, bool c);

        byte SubtractBytes(byte a, byte b);

    }
}
