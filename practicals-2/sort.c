#include <stdio.h>

int* sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int k = arr[i];
        int p = i;
        while (p >= 0 && k < arr[--p]) {
            arr[p+1] = arr[p];
        }
        arr[p+1] = k;
    }
    return arr;
}

int main() {
    int arr[10];
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < 10; i++) {
        printf(">> ");
        scanf("%d", arr+i);
    }
    sort(arr, 10);
    printf("The sorted array is :\n");
    for (int i = 0; i < 10; i++) printf("%d; ", arr[i]);
    
    return 0;
}
