#include <stack>
#include <iostream>
#include <string>
#include <sstream>

namespace tst {

	std::stack<std::string> numStack;
	std::stack<char> opStack;

	inline bool isdigit(char c) {
		return c >= '0' && c <= '9';
	}

	inline bool isoperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
	}

	inline bool isPreffered(char c, char c1) {
		if ((c == '+'|| c=='-') && (c1 == '/' || c1 == '*')) return true;
		else if ((c == '+' || c == '-') && (c1 == '+' || c1 == '-')) return true;
		else if ((c == '/' || c == '*') && (c1 == '/' || c1 == '*')) return true;
		else return false;
	}

	inline int todigit(char c) {
		return c - '0';
	}

	inline float math(int a, int b, char op) {
		if (op == '+') return a + b;
		else if (op == '-') return a - b;
		else if (op == '*') return a * b;
		else if (op == '/') return a / b;
		else return 0;
	}

	inline std::string reverse(std::string str) {
		std::stringstream stream;
		for (int i = str.length()-1; i >= 0; i--) {
			stream << str.c_str()[i];
		}
		return stream.str();
	}

	inline float pow(float a, int b) {
		float prod = 1;
		for (int i = 0; i < b; i++) prod *= a;
		return prod;
	}

	inline std::string ToString(char c) {
		std::stringstream stream;
		stream << c;
		return stream.str();
	}

	float parseNum(std::string str) {
		int i = 0, dec = str.length();
		float num = 0;
		while (i < str.length()) {
			if (str[i] == '.') dec = i;
			else if (isdigit(str[i])) num = num * 10 + todigit(str[i]);
			else return -1;
			i++;
		}
		if (dec != str.length()) num = num / pow(10, str.length() - dec - 1);
		return num;
	}

	std::string ConvertToPostfix(const std::string str) {
		
		std::stringstream stream;
		std::stringstream numstring;

		const char* cstr = str.c_str();
		int i = 0;
		while (cstr[i] != '\0') {
			if (isdigit(cstr[i]) || cstr[i] == '.') {
				numstring << cstr[i];
				std::cout << numstring.str() << std::endl;
				if (isoperator(cstr[i+1]) || cstr[i+1] == '\0') {
					numStack.push(numstring.str());
					numstring.str("");
				}
			}
			else {
				if (cstr[i] == ')') {
					while (opStack.top() != '(') {
						char op = opStack.top();
						opStack.pop();
						numStack.push(ToString(op));
					} opStack.pop();
				}
				else if (opStack.empty()) opStack.push(cstr[i]);
				else if (isPreffered(cstr[i], opStack.top())) {
					while (!opStack.empty() && (cstr[i], opStack.top())) {
						char op = opStack.top();
						opStack.pop();
						numStack.push(ToString(op));
					}
					opStack.push(cstr[i]);
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
		std::stack<char> mainStack;
		std::stack<float> numStack;
		for (int i = 0; i < exp.length(); i++) {
			if (isdigit(exp.at(i))) {
				numStack.push(todigit(exp.at(i)));
			} else if (isoperator(exp.at(i))) {
				int a = numStack.top();
				numStack.pop();
				int b = numStack.top();
				numStack.pop();
				float result = math(b, a, exp.at(i));
				numStack.push(result);
			}
		}
		return numStack.top();
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
	// std::cout << "Enter a number : ";
	// std::string str;
	// float num;
	// std::cin >> str;
	// num = tst::parseNum(str);
	// if (num < 0) std::cout << "Failed to parse!" << std::endl;
	// else std::cout << num << std::endl;
	std::cout << "Enter an expression : ";
	std::string exp;
	std::cin >> exp;
	std::cout << "Parsed : " << tst::ConvertToPostfix(exp) << std::endl;
    return 0;
}
