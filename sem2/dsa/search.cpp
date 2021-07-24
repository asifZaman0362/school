#include <iostream>

int lsearch(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
        else continue;
    }
    return -1;
}

int main() {
    int arr[] = { 65, 20, 10, 55, 32, 12, 50, 99 };
    int pos = lsearch(arr, sizeof(arr), 12);
    if (pos != -1)
        std::cout << "The item is " << pos + 1 << "th in the array\n";
    else std::cout << "The item doesn't exist in the array\n";
    return 0;
}
