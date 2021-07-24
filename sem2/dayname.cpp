#include <iostream>
#include <string>

int main() {
    int day_n;
    std::string dayname;
    std::cout << "Enter the weekday number : ";
    std::cin >> day_n;
    
    switch(day_n) {
        case 1:
            dayname = "Monday";
            break;
        case 2:
            dayname = "Tuesday";
            break;
        case 3:
            dayname = "Wednesday";
            break;
        case 4:
            dayname = "Thursday";
            break;
        case 5:
            dayname = "Friday";
            break;
        case 6:
            dayname = "Saturday";
            break;
        case 7:
            dayname = "Sunday";
            break;
        default:
            std::cerr << "Invalid input exception!";
    }
    
    std::cout << "The weekday for that index is " << dayname << std::endl;

    return 0;
}
