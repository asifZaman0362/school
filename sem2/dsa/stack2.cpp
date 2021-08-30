#include <iostream>
#include <stdlib.h>
#if defined(WIN32) || defined(WIN64)
#include <conio.h>
#endif

const unsigned short size = 50;
int stack[size];
int TOP;

inline void clear()
{
#ifdef linux
    system("clear");
#else
    system("cls");
#endif
}

#if !defined(WIN32) || !defined(WIN64)
inline void getch()
{
    char str[100];
    std::cout << "Enter any key to continue...";
    std::cin >> str;
}
#endif


void push ()
{
    if (TOP == size)
        std::cout << "\033[0;31mStack Overflow!\n\n\n\033[0;37m";
    else
    {
        int item;
        std::cout << "Enter the element to push: ";
        std::cin >> item;
        stack[TOP++] = item;
        std::cout << "\033[0;33mPushed " << item << " to the stack.\n\n\n\033[0;37m";
    }
    getch();
}

void pop ()
{
    if (TOP == 0)
        std::cout << "\033[0;31mStack Underflow!\n\n\n\033[0;37m";
    else
        std::cout << "\033[0;33mPopped " << stack[--TOP] << " from the stack!\n\n\n\033[0;37m";
    getch();
}

void peep ()
{
    if (TOP == 0)
        std::cout << "\033[0;31mStack is empty!\n\n\n\033[0;37m";
    else
        std::cout << "\033[0;33mThe topmost element is: " << stack[TOP - 1] << "\n\n\n\033[0;37m";
    getch();
}

void display ()
{
    clear();
    if (TOP == 0)
        std::cout << "\033[0;31mStack is empty!\n\n\n\033[0;37m";
    else
    {
        std::cout << "\033[0;33mThe stack is --\n\n";
        for (int i = 0; i < TOP; i++)
            std::cout << i + 1 << ". " << stack[i] << "\n";
        std::cout << "\033[0;37m\n\n\n";
    }
    getch();
}

int main()
{
    int option = 0;
    while (option != 5)
    {
        clear();
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
                std::cout << "\033[0;31mUnexpected input! Try again...\n\n\n\033[0;37m";
                getch();
        }
    }
    return 0;
}
