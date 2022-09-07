#include <cstddef>
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    std::stack<char> string_stack;
    size_t j = 0;
    for (size_t i = 0; i < input.length; i++) {
        if (input[i] == '.') {
            while (!string_stack.empty) {
                input[j++] = string_stack.top();
                string_stack.pop();
            }
        }
    }
    return 0;
}
