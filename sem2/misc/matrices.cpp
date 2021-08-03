#include <iostream>
#include "zutils.hpp"

#define PRINT_MAT(A, x, y) \
    for(int i = 0; i < x; i++) \
    tst::printarr(A+i*y, y, "|\t ", "\t ", " \t|");

void getMat(int *mat, int &x, int &y) {
    if (x < 0 || y < 0) {
        std::cout << "Enter row size: ";
        std::cin >> x;
        std::cout << "Enter column: ";
        std::cin >> y;
    }

    std::cout << "Enter matrix entries:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << "[" << i << "," << j << "] >> ";
            std::cin >> mat[i*y+j];
        }
    }
}

void addMat(int *a, int *b, int *c, int x, int y) {
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            c[i*y+j] = a[i*y+j] + b[i*y+j];
}


int main() {
    int matA[3*3], matB[3*3], matC[3*3], x = 3, y = 3;

    std::cout << "\n\nEnter first matrix:\n";
    getMat(matA, x, y);
    std::cout << "\n\nEnter second matrix:\n";
    getMat(matB, x, y);

    addMat(matA, matB, matC, x, y);
    
    tst::clear_screen();
    std::cout << "The entered matrices are :\n\n";
    PRINT_MAT(matA, x, y);
    std::cout << "\nAND\n\n";
    PRINT_MAT(matB, x, y);
    std::cout << "\n\nThe sum of the matrices = \n\n";
    PRINT_MAT(matC, x, y);
    
    return 0;
}
