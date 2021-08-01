#include <iostream>

void isort(int* arr, const int n)
{
    int i = 1;
    while (i < n) {
        int sel = arr[i];
        int j = i - 1;
        while ((j >= 0) && (sel < arr[j])) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = sel;
        i++;
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
    isort(arr, size);
    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "; ";
    std::cout << std::endl;

    return 0;
}

