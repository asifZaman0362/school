#include "alu.hpp"

namespace tst::dd {
    namespace ALU {

        inline int pow2 (int n) {
            int sum = 1;
            for (int i = 0; i < n; i++) sum *= 2;
            return sum;
        }

        byte::byte(bool arr[]) {
            for (int i = 0; i < 8; i++) {
                bits[i] = arr[i];
            }
        }

        int byte::Decimal() {
            int dec = 0;
            int sign = 1;
            bool* calcbits = bits;
            bool one[] = {0,0,0,0,0,0,0,1};
            if (bits[0]) {
                sign = -1;
                calcbits = SubtractBytes(byte(bits), byte(one)).x.bits;
                for(int i = 0; i < 8; i++) {
                    calcbits[i] = !calcbits[i];
                }
            }
            for (int i = 0; i < 8; i++) {
                dec += calcbits[i] * pow2(7-i);
            }
            return sign * dec;
        }

        vec<bool, bool> AddBits(bool a, bool b, bool c) {
            bool sum = XOR(XOR(a, b), c);
            bool carry = OR(AND(XOR(a, b), c), AND(a, b));
            return vec(sum, carry);
        }

        vec<byte, bool> AddBytes(byte a, byte b) {
            byte o;
            bool carry = 0;
            for (int i = 1; i <= 8; i++) {
                vec added = AddBits(a.bits[8-i], b.bits[8-i], carry);
                o.bits[8-i] = added.x;
                carry = added.y;
            }
            return vec(o, carry);
        }

        vec<bool, bool> SubtractBits(bool a, bool b, bool c) {
            bool dif = XOR(XOR(a, b), c);
            bool bor = OR(AND(b, c), AND(!a, XOR(b, c)));
            return vec(dif, bor);
        }

        vec<byte, bool> SubtractBytes(byte a, byte b) {
            byte o;
            bool borrow = 0;
            for (int i = 1; i <= 8; i++) {
                vec sub = SubtractBits(a.bits[8-i], b.bits[8-i], borrow);
                o.bits[8-i] = sub.x;
                borrow = sub.y;
            }
            return vec(o, borrow);
        }

    }
}