#include <isotream>

void ssort(int* arr, const int n)
{
    int i = 0;
    while (i < n-1) {
        int sel = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[sel]) sel = j;
        }
        if (sel != i) {
            int x = arr[sel]
            arr[sel] = arr[i];
            arr[i] = arr[sel];
        }
        i++;
    }
}

