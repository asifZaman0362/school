#include <iostream>
#include <stdlib.h>
#include <time.h>

namespace tst {

    template<typename T>
    inline void printarr(T* arr, int N, 
            const char* start="{ ", 
            const char* sep=", ",
            const char* end=" }", bool n=true) {
        std::cout << start;
        for (int i = 0; i < N; i++) {
            std::cout << arr[i] << (i < N-1 ? sep : end);
        }
        if (n) std::cout << "\n";
    }

    inline void clear_screen() {
#if defined(WIN32) || defined(WIN64)
        system("cls");
#else
        system("clear");
#endif
    }

    inline int* getRandomArray(int *arr, int len, int max=100) {
        //srand(time(0));
        for (int i = 0; i < len; i++) arr[i] = rand() % max;
        return arr;
    }

    
    /*void start_benchmark() {
        ref_time = clock();
    }*/

    void benchmark(const char* msg, unsigned int ref_time) {
        int dtime = clock() - ref_time;
        std::cout << msg << "\n";
        std::cout << "Took " << dtime/CLOCKS_PER_SEC << " seconds.\n";
    }

    inline bool check_sorted(int* arr, const int n)
    {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i+1])
                return false;
        }
        return true;
    }


}
