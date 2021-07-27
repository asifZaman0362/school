#include <functional>
#include "sort.cpp"
#include "zutils.hpp"

int main() {
    const int n = 10;
    std::function<bool(int, int)> comp = [](int a, int b) { return a < b; };
    int arr[10];

    tst::clear_screen();
    // Quick sort
    tst::getRandomArray(arr, n);
    std::cout << "Original array: ";
    tst::printarr<int>(arr, n);
    tst::qsort(arr, 0, n-1, comp);
    std::cout << "Quick sorted: ";
    tst::printarr<int>(arr, n);

    // Bubble sort
    tst::getRandomArray(arr, n);
    std::cout << "\n\nOriginal array: ";
    tst::printarr<int>(arr, n);
    tst::bsort(arr, n, comp);
    std::cout << "Bubble sorted: ";
    tst::printarr<int>(arr, n);

    // Selection sort
    tst::getRandomArray(arr, n);
    std::cout << "\n\nOriginal array: ";
    tst::printarr<int>(arr, n);
    tst::ssort(arr, n, comp);
    std::cout << "Selection sorted: ";
    tst::printarr<int>(arr, n);

    // Insertion sort
    tst::getRandomArray(arr, n);
    std::cout << "\n\nOriginal array: ";
    tst::printarr<int>(arr, n);
    tst::isort(arr, n, comp);
    std::cout << "Insertion sorted: ";
    tst::printarr<int>(arr, n);
    return 0;
}
