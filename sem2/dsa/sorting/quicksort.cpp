#include <iostream>

int partition(int *arr, int lo, int hi)
{
    int pivot = arr[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (arr[j] < pivot) {
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
            i++;
        }
    }
    int x = arr[i];
    arr[i] = arr[hi];
    arr[hi] = x;
    return i;
}

void qsort(int *arr, int lo, int hi)
{
    if (lo < hi) {
        int p = partition(arr, lo, hi);
        qsort(arr, lo, p - 1);
        qsort(arr, p + 1, hi);
    }
}

int main() {
    const int size = 10;
    int arr[size];
    std::cout << "Enter " << size << " integers:";
    for (int i = 0; i < size; i++) {
        std::cout << ">> ";
        std::cin >> arr[i];
    }
    qsort(arr, 0, size-1);
    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "; ";
    std::cout << std::endl;

    return 0;
}
