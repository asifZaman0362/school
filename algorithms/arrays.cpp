#include <iostream>

typedef unsigned int uint;

uint search_l(arr, n, x) {
    uint pos = -1, i = -1;
    while (++i < n) {
        pos = arr[i] == x ? i : pos;
    }
    if (i == -1) std::cout << "Element not found!\n";
    return pos;
}

uint search_b(arr, n, x) {
    uint pos = -1, mid = n / 2;
    while (arr[mid] != x) {

    }
}
