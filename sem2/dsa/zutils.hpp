#include <iostream>
#include <stdlib.h>

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

}
