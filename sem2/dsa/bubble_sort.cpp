#include <iostream>

void bsort(int* arr, const int n)
{
    bool sorted = false;
    int i = 1;
    while ((i < n) && (!sorted)) {
        sorted = true;
        for (int j = 0; j < n - i; j++) {
            if (arr[j+1] < arr[j]) {
                int x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
                sorted = false;
            }
         }
    }
}
