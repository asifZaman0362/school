#include <iostream>

class Fibonacci
{
public:
    Fibonacci () : 
        m_first(0), m_second(1), m_fib(1) {}
    
    void Increment ()
    {
        m_first = m_second;
        m_second = m_fib;
        m_fib = m_first + m_second;
    }
    
    void Display ()
    {
        std::cout << m_first << ";";
    }

private:
    int m_first;
    int m_second;
    int m_fib;
};

int main ()
{
    Fibonacci fib;
    for (int i = 0; i < 10; i++)
    {
        fib.Display();
        fib.Increment();
    }
    std::cout << std::endl;

    return 0;
}
