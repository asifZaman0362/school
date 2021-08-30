#include <iostream>

int Mul (int a, int b)
{
    return a * b;
}

int Mul (int a, int b, int c)
{
    return a * b * c;
}

int main ()
{
    int a, b, c;
    std::cout << "Enter three integers: ";
    std::cin >> a >> b >> c;
    std::cout << a << " * " << b << " = " << Mul(a, b) << "\n";
    std::cout << a << " * " << b << " * " << c <<  " = " << Mul(a, b, c) << "\n";
    return 0;
}
