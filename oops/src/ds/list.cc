#include "ds/list.hpp"
#include <iostream>

void print(const int& v) { std::cout << v << std::endl; }

int main() {
    zl::ds::List<int> list;
    list.insert(1, 0);
    list.insert(2, 1);
    list.insert(3, 2);
    list.insert(4, 1);
    for (size_t i = 4; i < 60; i++) {
        list.insert(i * 10, i);
    }
    list.remove(0);
    list.print_list(print);
    auto res = list.locate(330);
    std::cout << "at : " << res.unwrap() << std::endl;
    
    return 0;
}
