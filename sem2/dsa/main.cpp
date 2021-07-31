#include <functional>
#include "sort.cpp"
#include "zutils.hpp"

int main() {

    srand(time(0));
    const int n = 10000, tc = 500;
    int t = clock();
    std::function<bool(int, int)> comp = [](int a, int b) { return a < b; };
    std::function<bool(int, int)> chck = [](int a, int b) { return a <= b; };
    int arr[n];
    
    //tst::clear_screen();
    // Merge sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::msort(arr, n, comp);
        assert(tst::check_sorted(arr, n, chck));
    }
    std::cout << tc << " merge sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Quick sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::qsort(arr, 0, n-1, comp);
        assert(tst::check_sorted(arr, n, chck));
    }
    std::cout << tc << " quicksort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Bubble sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::isort(arr, n, comp);
        assert(tst::check_sorted(arr, n, chck));
    }
    std::cout << tc << " insertion sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    // Selection sort
    tst::getRandomArray(arr, n);
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::ssort(arr, n, comp);
        assert(tst::check_sorted(arr, n, chck));
    }
    std::cout << tc << " selection sort test passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";
    
    // Insertion sort
    for (int i = 0; i < tc; i++) {
        tst::getRandomArray(arr, n);
        tst::bsort(arr, n, comp);
        assert(tst::check_sorted(arr, n, chck));
    }
    std::cout << tc << " bubble sort tests passed!\n";
    t = clock() - t;
    std::cout << "Took " << t << " clicks over " << float(t)/CLOCKS_PER_SEC;
    std::cout << "\n";

    return 0;
}
