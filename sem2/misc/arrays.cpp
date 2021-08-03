#include <iostream>
#include "zutils.hpp"

template <typename T>
T* getArr(int& n) {
    if (n == -1) {
        std::cout << "Enter the size of the array: ";
        std::cin >> n;
    }
    T* arr = new int[n];

    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << ">> ";
        std::cin >> arr[i];
    }

    return arr;
}

int main() {
    int *arr, n = -1, x, p;
    arr = getArr<int>(n);
    tst::printarr(arr, n);
    std::cout << "Enter the new element: ";
    std::cin >> x;
    std::cout << "Insertion position (0-" << n - 1 << "): ";
    std::cin >> p;
    for (int i = n-1; i > p; i--) {
        arr[i] = arr[i-1];
    }
    arr[p] = x;
    tst::printarr(arr, n);

    delete[] arr;
    return 0;
}
