#include <iostream>
#include "zutils.hpp"

#define PRINT_MAT(A, x, y) \
    for(int i = 0; i < x; i++) \
    tst::printarr(A+i*y, y, "|\t ", "\t ", " \t|");

int *getMat(int &x, int &y) {
    if (x < 0 || y < 0) {
        std::cout << "Enter row size: ";
        std::cin >> x;
        std::cout << "Enter column: ";
        std::cin >> y;
    }
    int *mat = new int[x*y];
    std::cout << "Enter matrix entries:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << "[" << i << "," << j << "] >> ";
            std::cin >> mat[i*y+j];
        }
    }
    return mat;
}

int *addMat(int *a, int *b, int x, int y) {
    int *s = new int[x*y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            s[i*y+j] = a[i*y+j] + b[i*y+j];
    return s;
}


int main() {
    int *matA, *matB, *matC, x = 3, y = 3;

    std::cout << "\n\nEnter first matrix:\n";
    matA = getMat(x, y);
    std::cout << "\n\nEnter second matrix:\n";
    matB = getMat(x, y);

    matC = addMat(matA, matB, x, y);
    
    tst::clear_screen();
    std::cout << "The entered matrices are :\n\n";
    PRINT_MAT(matA, x, y);
    std::cout << "\nAND\n\n";
    PRINT_MAT(matB, x, y);
    std::cout << "\n\nThe sum of the matrices = \n\n";
    PRINT_MAT(matC, x, y);
    return 0;
}
