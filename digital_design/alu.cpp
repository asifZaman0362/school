#include "alu.hpp"

namespace tst::dd {
    namespace ALU {

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
                calcbits = SubtractBytes(byte(bits), byte(one)).bits;
                for(int i = 0; i < 8; i++) {
                    calcbits[i] = !calcbits[i];
                }
            }
            for (int i = 0; i < 8; i++) {
                dec += calcbits[i] * pow2(7-i);
            }
            return sign * dec;
        }

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

        vec SubtractBits(bool a, bool b, bool c) {
            bool dif = XOR(XOR(a, b).Out(), c).Out();
            bool bor = OR( AND(b, c).Out(), AND(!a, XOR(b, c).Out()).Out() ).Out();
            return vec(dif, bor);
        }

        byte SubtractBytes(byte a, byte b) {
            byte o;
            bool borrow = 0;
            for (int i = 1; i <= 8; i++) {
                vec sub = SubtractBits(a.bits[8-i], b.bits[8-i], borrow);
                o.bits[8-i] = sub.a;
                borrow = sub.b;
            }
            return o;
        }

    }
}