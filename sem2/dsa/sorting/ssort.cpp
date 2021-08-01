#include <iostream>

void ssort(int* arr, const int n)
{
    int i = 0;
    while (i < n-1) {
        int sel = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[sel]) sel = j;
        }
        if (sel != i) {
            int x = arr[sel];
            arr[sel] = arr[i];
            arr[i] = x;
        }
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
    ssort(arr, size);
    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "; ";
    std::cout << std::endl;

    return 0;
}
