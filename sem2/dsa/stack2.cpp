#include <iostream>
#include <stdlib.h>

const unsigned short size = 50;
int stack[size];
int TOP = -1;


void push ()
{
    if (TOP == size)
        std::cout << "Stack Overflow!\n\n\n";
    else
    {
        int item;
        std::cout << "Enter the element to push: ";
        std::cin >> item;
        stack[++TOP] = item;
        std::cout << "Pushed " << item << " to the stack.\n\n\n";
    }
}

int pop ()
{
    if (TOP == -1)
    {
        std::cout << "Stack Underflow!\n\n\n";
        return 0;
    }
    else
    {
        std::cout << "Popped " << stack[TOP] << " from the stack!\n\n\n";
        return stack[TOP--];
    }
}

int peep ()
{
    if (TOP == -1)
    {
        std::cout << "Stack is empty!\n\n\n";
        return 0;
    }
    else
    {
        std::cout << "The topmost element is: " << stack[TOP] << "\n\n\n";
        return stack[TOP];
    }
}

void display ()
{
    if (TOP == -1)
        std::cout << "Stack is empty!\n\n\n";
    else
    {
        std::cout << "The stack is --\n\n";
        for (int i = 0; i <= TOP; i++)
            std::cout << i + 1 << ". " << stack[i] << "\n";
        std::cout << "\n\n\n";
    }
}

int main()
{
    int option = 0;
    while (option != 5)
    {
        std::cout << "Select an operation:\n";
        std::cout << "1. Push\n2. Pop\n3. Peep\n4. Display\n5. Quit\n\n: ";
        std::cin >> option;
        switch (option)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                option = 5;
                break;
            default:
                std::cout << "Unexpected input! Try again...";
        }
    }
    return 0;
}
