#include <functional>
#include "sort.cpp"
#include "zutils.hpp"

int lsearch(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
        else continue;
    }
    return -1;
}

int bsearch(int* arr, int n, int x) {
    if (x > arr[n-1]) return -1;
    int mid, beg = 0, end = n-1;
    while (beg <= end) {
        mid = (end + beg) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) end = mid - 1;
        else beg = mid + 1;
    }

    return -1;
}

int main() {
    srand(time(0));
    int arr[10];
    tst::getRandomArray(arr, 10);
    std::function<bool(int, int)> comp = [](int a, int b) { return a < b; };
    
    tst::qsort(arr, 0, 10, comp);
    
    std::cout << "The sorted array is: \n";
    tst::printarr(arr, 10);
    int term = arr[rand() % 10];
    int pos = bsearch(arr, 10, term);
    std::cout << "The search term is = " << term << std::endl;
    if (pos != -1)
        std::cout << "The item has index " << pos << "\n";
    else std::cout << "The item doesn't exist in the array\n";

    return 0;
}
