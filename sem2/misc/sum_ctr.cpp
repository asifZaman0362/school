#include <iostream>

class Adder
{
public:
    Adder (int x, int y)
    {
        sum = x + y;
    }
    void print()
    {
        std::cout << sum << "\n";
    }
private:
    int sum;
    int x, y;
};

int main ()
{
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    Adder add(x, y);
    add.print();
    return 0;
}
