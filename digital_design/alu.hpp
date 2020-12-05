#pragma once
#include "logic_gates.hpp"


namespace tst::dd {
    namespace ALU {

        template <typename T1, typename T2>
        struct vec {
            T1 x;
            T2 y;
            vec();
            vec(T1 x, T2 y) : x(x), y(y) {}
        };

        struct byte {
            bool bits[8] = { 0,0,0,0,0,0,0,0 };
            byte() {}
            byte(bool[]);
            int Decimal();
        };

        inline int pow2 (int);

        vec<bool, bool> AddBits(bool, bool, bool);

        vec<byte, bool> AddBytes(byte, byte);

        vec<bool, bool> SubtractBits(bool, bool, bool);

        vec<byte, bool> SubtractBytes(byte, byte);

    }
}
