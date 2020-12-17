#include <stack>
#include <iostream>
#include <string>
#include <sstream>

namespace tst {

	std::stack<int> numStack;
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

	std::string ConvertToPostfix(const std::string str) {
		const char* cstr = str.c_str();
		int i = 0;
		while (cstr[i] != '\0') {
			if (isdigit(cstr[i])) numStack.push(cstr[i] - '0');
			else {
				if (isPreffered(cstr[i], opStack.top())) {
					char c = opStack.top();
					opStack.pop();
					opStack.push(cstr[i]);
					opStack.push(c);
				}
			}
		}
	}

	float ParsePostfix(std::string exp) {

	}

	std::string CleanupExpession(const std::string str, bool* result) {
		*result = true;
		std::stringstream sstr;
		const char* cstr = str.c_str();
		int i = 0;
		while (cstr[i] != '\0') {
			if (cstr[i] == ' ') i++;
			else if (tst::isdigit(cstr[i]) || tst::isoperator(cstr[i])) {
				sstr << cstr[i];
			} else { *result = false; break; }
		}

		return sstr.str();
	}

}

int main() {
	bool flag;
	std::cout << "Enter an arithmetic expression : ";
	char exp[100];
	fgets(exp, 100, stdin);
	std::string clean_exp = tst::CleanupExpession(exp, &flag);
	if (!flag) {
		std::cout << "Failed to parse the expression!" << std::endl;
		return -1;
	}
	std::cout << clean_exp << std::endl;
	std::string postfix = tst::ConvertToPostfix(clean_exp);
	std::cout << postfix << std::endl;
	float result = tst::ParsePostfix(clean_exp);
	std::cout << clean_exp << " = " << result << std::endl;
}