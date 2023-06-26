#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void postfixCalculator(string input) {
	cout << "Postfix Expression: " << input << ", Evaluation Result: "; //start outputing message
	stack<int> s;
	int num1 = 0, num2 = 0;

	for (auto c : input) {
		if (isdigit(c)) { //checs each char and if it is a digit converts it to a digit
			int i = c - '0';
			s.push(i);
		}
		else if (c != ' ') {
			if (s.empty()) { //if there is an operator but no numbers for the operator then invalid
				cout << "INVALID" << endl;
				break;
			}

			num2 = s.top(); //take the top of the stack to be the second operand
			s.pop(); //remove from stack

			if (s.empty()) { //if there is an operator but no numbers for the operator then invalid
				cout << "INVALID" << endl;
				return;
			}

			num1 = s.top(); //take the top of the stack to be the first operand
			s.pop(); // remove from the stack

			if (c == '*')
				s.push(num1 * num2); //if multiplication then push the product into the stack

			else if (c == '/')
				if (num2 == 0){ //checks if second operand is zero and if so gives an error
					cout << "INVALID (cannot divide by zero)" << endl;
					return;
				}
				else
					s.push(num1 / num2); //divide the numbers and then push into the stack

			else if (c == '+')
				s.push(num1 + num2); //if addition push the result into the stack

			else if (c == '-')
				s.push(num1 - num2); //if subtraction push the result into the stack
		}
	}

	int resultCheck = s.top(); //this checks if there is only one element left after everything
	s.pop();

	if (s.empty())
		cout << resultCheck << endl; //if there is only one element in the stack then that is the result
	else
		cout << "INVALID" << endl; //if not then the expression was invalid
}

int main() {
	int num = 0;
	string temp;
	vector<string> expressions;

	while (num != -1) { //loops which asks for expressions until the user inputs -1
		cout << "Please enter a postfix expression or -1 to stop:" << endl;
		getline(cin, temp);
		if (temp == "-1") {
			num = -1;
			break;
		}
		expressions.push_back(temp); //push the expresssions into a vector of strings
	}

	for (auto i : expressions) { //find the result of each expression in the vector
		postfixCalculator(i);
	}
}