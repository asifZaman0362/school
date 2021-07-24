#include <iostream>
#include "sort.cpp"
#include "zutils.hpp"


int main() {
    int a[] = { 56, 4, 76, 32, 31, 2, 65, 87, 12, 6 };
    tst::printarr<int>(a, 10);
    tst::bsort(a, 10);
    tst::printarr<int>(a, 10);
    return 0;
}
