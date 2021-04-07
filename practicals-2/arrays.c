#include <stdio.h>

int main() {
    unsigned int n;
    printf("Enter the number of elements : ");
    scanf("%u", &n);
    int arr[n], sum = 0;
    printf("Enter the elements :\n");
    for (int i = 0; i < n; i++) {
        printf(">> ");
        scanf("%d", arr+i);
        sum += arr[i];
    }
    printf("Elements of the array : ");
    for (int i = 0; i < n; i++) printf("%d%s", arr[i], i == n - 1 ? "\n" : ", ");
    printf("Sum of all elements : %d\n", sum);

    return 0;
}
