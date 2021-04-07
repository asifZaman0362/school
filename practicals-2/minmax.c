#include <stdio.h>

int main() {
    int arr[10], smallest = 0, greatest = 0;
    printf("Enter the array elements :\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", arr+i);
        if (arr[i] < smallest || i == 0) smallest = arr[i];
        if (arr[i] > greatest || i == 0) greatest = arr[i];
    }
    printf("Maximum = %d; Minimum = %d\n", greatest, smallest);
    return 0;
}
