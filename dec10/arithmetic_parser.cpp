#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stack>
#include <iostream>


bool compareOp(char op1, char op2) {
    if (op1 == '*' || op1 == '/') return true;
    else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) return false;
    else if ((op1 == '+' || op1 == '-') && (op2 == '-' || op2 == '+')) return true;
    else return true;
}


bool parseNum(const char* token, float* outNum, int n) {

    int i = 0;
    float num = 0;
    int dec = -1;
    while (i < n) {
        if (token[i] == '.') dec = i;
        else if (token[i] - '0' >= 0 && token[i] - '0' <= 9) num = (num * 10) + (token[i] - '0');
        else return false;
        ++i;
    }

    while (--i > dec && dec > 0) num /= 10;
    
    *outNum = num;
    return true;

}


bool parseOperator(const char token, char* outOp) {
    if (token == '+' || token == '-' || token == '*' || token == '/') 
    {
        *outOp = token;
        return true;
    }
    else return false;
}


float parseExp(std::string str) {
    std::stack<float> numStack;
    std::stack<char> opStack;
    int i = 0, j = 0;
    std::string token;
    const char* ex = str.c_str();
    while (i <= str.length()) {
        char op = '+';
        if (parseOperator(ex[i], &op) || ex[i] == '\0') {
            if (opStack.empty()) {
                float num;
                parseNum(token.c_str(), &num, token.length());
                opStack.push(op);
                numStack.push(num);
                token = "";
            }
            else if (ex[i] != '\0') {
                if (compareOp(opStack.top(), op)) {
                    float num;
                    if (parseNum(token.c_str(), &num, token.length())) {
                        float res = 0;
                        if (opStack.top() == '*') res = numStack.top() * num;
                        else if (opStack.top() == '/') res = numStack.top() / num;
                        else if (opStack.top() == '-') res = numStack.top() - num;
                        else if (opStack.top() == '+') res = numStack.top() + num;
                        numStack.pop();
                        numStack.push(res);
                        std::cout << res;
                        opStack.push(op);
                        token = "";
                    } else return false;
                }
            } else if (ex[i] == '\0') {
                float num;
                if (parseNum(token.c_str(), &num, token.length())) {
                    float res = 0;
                    std::cout << num << "; " << numStack.top();
                    if (opStack.top() == '*') res = numStack.top() * num;
                    else if (opStack.top() == '/') res = numStack.top() / num;
                    else if (opStack.top() == '-') res = numStack.top() - num;
                    else if (opStack.top() == '+') res = numStack.top() + num;
                    numStack.push(res);
                }
            }
        } else {
            std::stringstream str;
            str << ex[i];
            token.append(str.str());
        }
        i++;
    }
    return numStack.top();
}


int main() {
    char exp[100];
    char cleanExp[100];
    float result;
    printf("Enter an arithmetic expression >> ");
    std::cin >> exp;
    result = parseExp(exp);
    std::cout << "result = " << result << std::endl;
    return 0;
}