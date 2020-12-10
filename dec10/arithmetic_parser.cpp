#include <stdio.h>
#include <string.h>
#include <stack>


#define bool    unsigned char
#define false   0
#define true    1


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


bool parseExp(const char* ex, float* out) {

    std::stack<float> stNum;
    std::stack<char> stOp;

    char token[100];
    int i = 0, i_t = 0;
    while (ex[i] != '\0' && ex[i] != '\n') {
        char _op;
        if (parseOperator(ex[i], &_op)) {
            if (i_t > 0) {
                float num;
                if (parseNum(token, &num, i_t)) stNum.push(num);
            }
            stOp.push(_op);
            i_t = 0;
        } else token[i_t++] = ex[i];
    }
    return true;
}


int main() {
    char exp[100];
    char cleanExp[100];
    float result;
    printf("Enter an arithmetic expression >> ");
    scanf("%s", exp);
    //cleanUpExpression(exp, cleanExp);
    printf(cleanExp);
    return 0;
}