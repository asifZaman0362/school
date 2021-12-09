#include <iostream>

int linearSearch (int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x) return i;
        else continue;
    }
    return -1;
}

int main ()
{
    int arr[10];
    std::cout << "Enter 10 numbers: ";
    for (int i = 0; i < 10; i++)
        std::cin >> arr[i];
    int num;
    std::cout << "Enter the number to search: ";
    std::cin >> num;
    int pos = linearSearch(arr, 10, num);
    if (pos < 0) std::cout << "Number doesn't exist in the array!\n";
    else std::cout << "The number is in index: " << pos << "\n";
    return 0;
}
