#include <iostream>

inline int get_half(const int a) {
    return (a + a % 2)/2;
}

void merge(int* a, int* b, int* c, int* q, const int n, int m)
{
    int q_len = 0, q_ptr = 0; // Setup Queue parameters
    int i = 0;
    int l = n + m;
    //q[0] = a[0];
    for (int k = 0; k < l; k++) {
        if (k < n) q[k] = a[k]; // Copy the left side to the queue
        // Since the queue is already sorted, by principle, 
        // check against the lowest (first) term in it
        if ((i < m) && ((q_ptr >= n) || (b[i] < q[q_ptr]))) {
            // If the current element in the right half exceeds the
            // queue (left half), set the current element to that
            c[k] = b[i++];
        } else {
            // If the queue has the smaller element, move that to
            // the current position instead and update the queue
            c[k] = q[q_ptr];
            q_ptr++;
        }
    }
}

int* split_merge(int* a, int* b, const int n)
{
    if (n == 1) return a;
    int h1 = get_half(n);
    int h2 = n - h1;
    int* left = split_merge(a, b, h1);
    int* right = split_merge(a+h1, b, h2);
    merge(left, right, a, b, h1, h2);
        
    return a;
}

void msort(int* a, const int n)
{
    // Makes a one-time 
    // allocation of 1/2(n) for bufferring
    int b[get_half(n)];
    split_merge(a, b, n);
}


int main() {
    const int size = 10;
    int arr[size];
    std::cout << "Enter " << size << " integers:";
    for (int i = 0; i < size; i++) {
        std::cout << ">> ";
        std::cin >> arr[i];
    }
    msort(arr, size);
    std::cout << "The sorted array is:\n";
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << "; ";
    std::cout << std::endl;

    return 0;
}
