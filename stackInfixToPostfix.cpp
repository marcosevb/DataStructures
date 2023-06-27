#include <iostream>
#include <string>
#include <stack>
using namespace std;

int opPrecedence(char c) { //this is a function which returns the precedence of an operator

	if (c == '(') //parentheses are a special case which is why they each have their own value
		return 0;
	else if (c == ')')
		return 1;
	else if (c == '*') //* and / have mid precedence with a value of 2
		return 2;
	else if (c == '/')
		return 2;
	else if (c == '+') //lowest precedence operators + and - have the highest value of 3
		return 3;
	else if (c == '-')
		return 3;
	else                //everything else will return -1
		return -1;
}

string I2PConvertor(const string& infix_expr) { //this is my function which converts infix expressions to postfix expressions

	stack<char> ops; //stack which will hold the operators, string for the resulting expression
	string result;
	int pCheck1 = -1, pCheck2 = -1; //pCheck1 is precedence value for the new char while pCheck2 is the precedence value for the top of the stack

	for (auto c : infix_expr) { //this loop goes through each char in the input string
		pCheck1 = opPrecedence(c);

		if (pCheck1 < 0) { //if the char is not an operator then just add it to the result
			result += c;
		}
		else {
			if (ops.empty()) { //if the stack is empty then just add the operator to the stack and update pCheck2
				ops.push(c);
				pCheck2 = pCheck1;
			}
			else if (pCheck2 == 0) { //this is the special case for '('
				
				if (pCheck1 == 1) { //this is the special case for ')'
					pCheck2 = opPrecedence(ops.top()); 
					while (pCheck2 != 0) { //update pCheck2 and then pop all operators into the result until we reach '('
						result += ops.top();
						ops.pop();
						pCheck2 = opPrecedence(ops.top());
					}
					ops.pop(); //once we reach '(' then pop it out of the stack
				}
				else { //if not then just push the operator into the stack
					ops.push(c);
				}

			}
			else {
				if (pCheck1 >= pCheck2) { //this checks which precedence is higher

					result += ops.top(); //if the value in the stack has a higher precedence then put into result then pop from stack
					ops.pop();

				}
				ops.push(c); //then place the new operator in the stack and update pCheck2
				pCheck2 = pCheck1;
			}
		}

	}

	while (!ops.empty()) { //if there are any operator still in the stack after going through the input string then pop them into the result and out of the stack
		result += ops.top();
		ops.pop();
	}

	return result; //finally return the resulting string
}

int main() {
	string infix1 { "a*b+c" }; //main function to test the infix to postfix converter
	string infix2 { "a-b*c" };
	string infix3 { "(a+b)/c" };
	string infix4 { "(a+b)*(c-d)" };

	cout << "Infix to Postfix Expression Converter!" << endl;

	// expected: ab*c+
	cout << infix1 << " -> " << I2PConvertor(infix1) << endl;

	// expected: abc*-
	cout << infix2 << " -> " << I2PConvertor(infix2) << endl;

	// expected: ab+c/
	cout << infix3 << " -> " << I2PConvertor(infix3) << endl;

	// expected: ab+cd-*
	cout << infix4 << " -> " << I2PConvertor(infix4) << endl;

	return 0;
}