#include "alu.hpp"
#include <iostream>


using namespace tst::dd;

int main() {
    bool abits[] = {0,0,1,0,0,0,0,0};
    bool bbits[] = {0,0,1,1,1,0,0,0};
    ALU::byte a(abits);
    ALU::byte b(bbits);
    ALU::byte c = ALU::SubtractBytes(a, b);
    std::cout << c.Decimal() << std::endl;
    return 0;
}
