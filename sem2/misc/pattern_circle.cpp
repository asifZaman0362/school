#include <iostream>

inline int abs(int x) { return x<0 ? 0-x : x; }

int main(int argc, char** argv){
    int r = 0;
    if (argc > 1) r = argv[1][0] - '0';
    else {
        std::cout << "Enter the size : ";
        std::cin >> r;
    }
    for (int y=0; y<r*2+1; y++) {
        for (int x=0; x<r*2+1; x++) {
            if ((abs(r-x)==y) || abs(r-x)==abs(2*r-y)) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
}
