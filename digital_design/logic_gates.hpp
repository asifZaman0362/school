#pragma once


namespace tst::dd {


    #define OR(a, b) a || b
    #define XOR(a, b) a != b
    #define AND(a, b) a && b
    #define NOT(a) !a
    #define NOR(a, b) NOT(OR(a, b))
    #define XNOR(a, b) NOT(XOR(a, b))
    #define NAND(a, b) NOT(AND(a, b))


    struct Gate {

    protected:
        bool in1;
        bool in2;

    public:
        Gate(bool in1, bool in2) {
            this->in1 = in1;
            this->in2 = in2;
        }
        void Update(int node1, int node2) {
            in1 = node1 > 0 ? node1 : in1;
            in2 = node2 > 0 ? node2 : in2;
        }
        virtual bool Out() = 0;
    };

    struct AndGate : public Gate {
        AndGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return AND(in1, in2);
        }
    };

    struct OrGate : public Gate {
        OrGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return OR(in1, in2);
        }
    };

    struct NotGate : public Gate {
        NotGate(bool in) : Gate(in, in) {}
        virtual bool Out() override {
            return NOT(in1);
        }
    };

    struct XorGate : public Gate {
        XorGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return XOR(in1, in2);
        }
    };

    struct NandGate : public Gate {
        NandGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return NAND(in1, in2);
        }
    };

    struct NorGate : public Gate {
        NorGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return NOR(in1, in2);
        }
    };

    struct XnorGate : public Gate {
        XnorGate(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return NOT(XOR(in1, in2));
        }
    };
    
}