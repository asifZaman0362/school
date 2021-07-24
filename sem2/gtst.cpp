#include <iostream>

int main() {
    int a, b, c, g = 0;
    std::cout << "Enter the numbers :\n";
    std::cin >> a >> b >> c;
    if (a > b && a > c) g = a;
    else if (b > c) g = b;
    else g = c;
    std::cout << "The greatest is " << g << std::endl;
    return 0;
}
