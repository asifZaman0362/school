#include <functional>
#include "sort.cpp"
#include "zutils.hpp"

int main() {

    srand(time(0));
    const int n = 100, tc = 50;
    int t = clock();
    int arr[n];
    
    //tst::clear_screen();
    // Merge sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::msort(arr, n);
        assert(tst::check_sorted(arr, n));
    }
    std::cout << tc << " merge sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Quick sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::qsort(arr, 0, n-1);
        assert(tst::check_sorted(arr, n));
    }
    std::cout << tc << " quicksort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Bubble sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::isort(arr, n);
        assert(tst::check_sorted(arr, n));
    }
    std::cout << tc << " insertion sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Selection sort
    tst::getRandomArray(arr, n);
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::ssort(arr, n);
        assert(tst::check_sorted(arr, n));
    }
    std::cout << tc << " selection sort test passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";
    
    // Insertion sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::bsort(arr, n);
        assert(tst::check_sorted(arr, n));
    }
    std::cout << tc << " bubble sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    return 0;
}
