#include <ncurses.h>
#include <iostream>

int main ()
{
    initscr();
    //while (true)
    //{
    std::cout << "HELLO";
    auto key = getch();
        //if (key == 'q') break;
    //}
    endwin();
    std::cout << key;
    return 0;
}
