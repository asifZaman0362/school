  1 #include <stdio.h>
  2 
  3 int main() {
  4     int arr[10];
  5     printf("Enter data : ");
  6     for (int i = 0; i < 10; i++) {
  7         scanf("%d", arr+i);
  8     }
  9     for (int i = 0; i < 10; i++) {
 10         for (int j = i+1; j < 10; j++) {
 11             if (arr[i] > arr[j]) {
 12                 int temp = arr[i];
 13                 arr[i] = arr[j];
 14                 arr[j] = temp;
 15             }
 16         }
 17     }
 18     printf("Sorted array: \n");
 19     for (int i = 0; i < 10; i++) {
 20         printf("%d;", arr[i]);
 21     }
 22     return 0;
 23 }
