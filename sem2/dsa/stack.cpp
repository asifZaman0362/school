#include <iostream>

#define MIN -2147483648

class Stack
{
public:
    Stack (const size_t size) : m_size(size), m_top(0), m_arr{} {}

    void Push (int item)
    {
        if (m_top < m_size)
            m_arr[m_top++] = item;
        else
            std::cerr << "Stack overflow!\n";
    }

    int Pop ()
    {
        if (m_top > 0)
            return m_arr[--m_top];
        else
        {
            std::cerr << "Stack underflow!\n";
            return MIN;
        }
    }

    int Peep ()
    {
        if (m_top > 0)
            return m_arr[m_top - 1];
        else
        {
            std::cerr << "Stack is empty!\n";
            return MIN;
        }
    }

    void Display ()
    {
        std::cout << "\nThe stack is:\n";
        for (size_t i = 0; i < m_top; i++)
            std::cout << i << ")\t" << m_arr[i] << "\n";
    }

private:
    const size_t m_size;
    size_t m_top;
    int m_arr[100];
};


int main ()
{
    Stack stack(10);
    short opt = 0;
    while (opt != 5)
    {
        std::cout << "Select an operation:\n";
        std::cout << "1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n\n: ";
        std::cin >> opt;
        int x;
        switch (opt)
        {
            case 1:
                std::cout << "Enter a number: ";
                std::cin >> x;
                stack.Push(x);
                break;
            case 2:
                x = stack.Pop();
                if (x != MIN)
                    std::cout << "The popped element is: " << x << "\n";
                break;
            case 3:
                x = stack.Peep();
                if (x != MIN)
                    std::cout << "The top element is: " << x << "\n";
                break;
            case 4:
                stack.Display();
                break;
            default:
                opt = 5;
        }
    }
    return 0;
}
