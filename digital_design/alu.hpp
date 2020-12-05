#pragma once
#include "logic_gates.hpp"


namespace tst::dd {
    namespace ALU {

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

        inline int pow2 (int);

        vec AddBits(bool, bool, bool);

        byte AddBytes(byte, byte);

        vec SubtractBits(bool, bool, bool);

        byte SubtractBytes(byte, byte);

    }
}
