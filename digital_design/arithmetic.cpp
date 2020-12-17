#include <stack>
#include <iostream>
#include <string>
#include <sstream>

namespace tst {

	std::stack<char> numStack;
	std::stack<char> opStack;

	inline bool isdigit(char c) {
		return c >= '0' && c <= '9';
	}

	inline bool isoperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
	}

	inline bool isPreffered(char c, char c1) {
		if ((c == '+'|| c=='-') && (c1 == '/' || c1 == '*')) return true;
		else return false;
	}

    inline std::string reverse(std::string str) {
        std::stringstream stream;
        for (int i = str.length()-1; i >= 0; i--) {
            stream << str.c_str()[i];
        }
        return stream.str();
    }

	std::string ConvertToPostfix(const std::string str) {
		std::stringstream stream;
        
        const char* cstr = str.c_str();
		int i = 0;
		while (cstr[i] != '\0') {
			if (isdigit(cstr[i])) numStack.push(cstr[i]);
			else {
                if (cstr[i] == ')') {
                    while (opStack.top() != '(') {
                        char op = opStack.top();
                        opStack.pop();
                        numStack.push(op);
                    }
                }
				if (opStack.empty()) opStack.push(cstr[i]);
                else if (isPreffered(cstr[i], opStack.top())) {
                    char op = opStack.top();
                    opStack.pop();
                    opStack.push(cstr[i]);
                    numStack.push(op);
                } else opStack.push(cstr[i]);
			}
            i++;
		}
        while (!numStack.empty()) {
            stream << numStack.top();
            numStack.pop();
        }
        std::string st1 = reverse(stream.str());
        std::stringstream stream2;
        while (!opStack.empty()) {
            stream2 << opStack.top();
            opStack.pop();
        }
        std::string st2 = stream2.str();
        std::stringstream strf;
        strf << st1 << st2;
        return strf.str();
	}

	float ParsePostfix(std::string exp) {

	}

	std::string CleanupExpession(const std::string str) {
		std::stringstream sstr;
		const char* cstr = str.c_str();
		int i = 0;
		while (cstr[i] != '\0') {
			if (cstr[i] == ' ') { i++; continue; }
			else if (tst::isdigit(cstr[i]) || tst::isoperator(cstr[i])) {
				sstr << cstr[i];
			} else break;
            i++;
		}

		return sstr.str();
	}

}

int main() {
	bool flag;
	std::cout << "Enter an arithmetic expression : ";
	char exp[100];
	fgets(exp, 100, stdin);
	std::cout << exp << std::endl;
    std::string clean_exp = tst::CleanupExpession(exp);
	std::cout << clean_exp << std::endl;
	std::string postfix = tst::ConvertToPostfix(clean_exp);
	std::cout << postfix << std::endl;
	//float result = tst::ParsePostfix(clean_exp);
	//std::cout << clean_exp << " = " << result << std::endl;
    return 0;
}
