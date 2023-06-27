#include <iostream>
#include <list>
using namespace std;


void factorial(int n) { // function to find the factorial of a number
	list<int> result; //list which will hold the result
	result.push_back(1); //starting value will be 1
	
	int carry = 0;

	for (int i = 2; i <= n; i++) { //this will go through each number from 2 to the input n
		
		for (auto it = result.begin(); it != result.end(); it++) { //this will go from the start of the result to the end 
			int product = i * (*it) + carry; //calculating the product of each digit
			*it = product % 10; //updating the value
			carry = product / 10;   //updating the carry
		}

		while (carry != 0) { //this will add the carry bit to the result
			result.push_back(carry % 10);    
			carry = carry / 10;             
		}
	}

	cout << n << "! is equal to: " << endl;

	for (auto it = result.rbegin(); it != result.rend(); it++) //print the result in reverse which will give the correct value for n!
		cout << *it;

	cout << endl << endl;
}

int main() {
	int number = 0;
	while (number != -1) {
		cout << "Please enter an positive integer greater than 0 but less than 1024: (-1 to quit)" << endl; //ask for user input
		cin >> number;
		cout << endl;

		if (number != -1)
			factorial(number); //call the function
	}
	
}