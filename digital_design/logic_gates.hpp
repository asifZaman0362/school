#pragma once


namespace tst::dd {
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

    struct AND : public Gate {
        AND(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return in1 && in2;
        }
    };

    struct OR : public Gate {
        OR(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return in1 || in2;
        }
    };

    struct NOT : public AND {
        NOT(bool in) : AND(in, in) {}
        virtual bool Out() override {
            return !AND::Out();
        }
    };

    struct XOR : public Gate {
        XOR(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return in1 != in2;
        }
    };

    struct NAND : public Gate {
        NAND(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return !(in1 && in2);
        }
    };

    struct NOR : public Gate {
        NOR(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return !(in1 || in2);
        }
    };

    struct XNOR : public Gate {
        XNOR(bool in1, bool in2) : Gate(in1, in2) {}
        virtual bool Out() override {
            return in1 == in2;
        }
    };
    
}