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
            byte(bool arr[]) {
                for (int i = 0; i < 8; i++) {
                    bits[i] = arr[i];
                }
            }
            int Decimal() {
                int dec = 0;
                for (int i = 0; i < 8; i++) {
                    dec += bits[i] * pow2(7-i);
                }
                return dec;
            }
        };

        vec AddBits(bool a, bool b, bool c) {
            bool sum = XOR(XOR(a, b).Out(), c).Out();
            bool carry = OR( AND( XOR(a, b).Out(), c ).Out(), AND(a, b).Out() ).Out();
            return vec(sum, carry);
        }

        byte AddBytes(byte a, byte b) {
            byte o;
            bool carry = 0;
            for (int i = 1; i <= 8; i++) {
                vec added = AddBits(a.bits[8-i], b.bits[8-i], carry);
                o.bits[8-i] = added.a;
                carry = added.b;
            }
            return o;
        }

    }
}