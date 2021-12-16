#include <iostream>

void bsort(int* arr, const int n)
{
    bool sorted = false;
    int i = 0;
    while ((++i < n) && (!sorted)) {
        sorted = true;
        for (int j = 0; j < n - i; j++) {
            if (arr[j+1] < arr[j]) {
                int x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
                sorted = false;
            }
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;
    int arr[size];
    std::cout << "Enter " << size << " integers:";
    for (int i = 0; i < size; i++) {
        std::cout << ">> ";
        std::cin >> arr[i];
    }
    bsort(arr, size);
    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "; ";
    std::cout << std::endl;

    return 0;
}
