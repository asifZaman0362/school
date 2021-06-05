#include "zhash.hpp"
#include <iostream>

int main() {
    auto hash = zstd::hash("ee");
    std::cout << hash << std::endl;
    return 0;
}
