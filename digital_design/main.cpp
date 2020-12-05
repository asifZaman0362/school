#include "alu.hpp"
#include <iostream>


using namespace tst::dd;

int main() {
    bool abits[] = {0,0,0,0,1,1,1,1};
    bool bbits[] = {0,0,1,0,0,0,0,1};
    ALU::byte a(abits);
    ALU::byte b(bbits);
    ALU::byte c = ALU::AddBytes(a, b).x;
    std::cout << a.Decimal() << " + " << b.Decimal() << " = " << c.Decimal() << std::endl;
    std::cout << a.Decimal() << " - " << b.Decimal() << " = " << ALU::SubtractBytes(a, b).x.Decimal() << std::endl;
    std::cout << c.Decimal() << " - " << a.Decimal() << " = " << ALU::SubtractBytes(c, a).x.Decimal() << std::endl;
    return 0;
}
