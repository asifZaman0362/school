#include <iostream>

class Stack
{
public:
    Stack (const size_t max) : m_max(max), m_top(0), m_arr{}
    {}
    
    void Push (const int item)
    {
        if (m_top >= m_max)
        {
            std::cerr << "Stack overflow!" << std::endl;
            return;
        } else m_arr[m_top++] = item;
    }

    int Pop ()
    {
        if (m_top <= 0)
        {
            std::cerr << "Stack Underflow!" << std::endl;
            return 0;
        } else return m_arr[--m_top];
    }

    int Peep ()
    {
        if (m_top <= 0)
        {
            std::cerr << "Stack is empty!" << std::endl;
            return 0;
        } else return m_arr[m_top-1];
    }

    void Display ()
    {
        if (m_top <= 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        else
        {
            std::cout << "\n\033[0;35mThe stack is:\n";
            for (int i = 0; i < m_top; i++)
                std::cout << "\033[0;35m" << i << ":\t" << m_arr[i] << "\033[0m\n";
        }
    }

private:
    const size_t m_max;
    int m_arr[100];
    int m_top;
};

int main ()
{
    Stack stack(30);
    int opt = 0;
    while (opt != 5)
    {
        int val;
        std::cout << "\nSelect an operation:\n";
        std::cout << "1. Push\n2. Pop\n3. Peep\n4. Display\n5. Quit\n\n: ";
        std::cin >> opt;
        switch (opt)
        {
            case 1:
                std::cout << "Enter the value to insert: ";
                std::cin >> val;
                stack.Push(val);
                break;
            case 2:
                val = stack.Pop();
                std::cout << "\033[0;32mPopped item is: " << val << "\033[0m\n";
                break;
            case 3:
                val = stack.Peep();
                std::cout << "\033[0;32mThe topmost item is: " << val << "\033[0m\n";
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                opt = 5;
                break;
            default:
                std::cout << "Invalid option! Try again...\n";
        }
    }
    return 0;
}
