#include "zutils.hpp"

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    tst::printarr(arr, 4);
    tst::printarr(arr+4, 4);
    return 0;
}
