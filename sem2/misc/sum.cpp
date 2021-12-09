#include <iostream>

int main() {
    int n, sum = 0;
    float avg;
    std::cout << "Enter the number of terms :";
    std::cin >> n;
    std::cout << "Enter the numbers:\n";
    
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        sum += x;
    }
    avg = (float)sum / n;

    std::cout << "Sum of the series = " << sum << "; Average = " << avg << std::endl;
    
    return 0;
}
