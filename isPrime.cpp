#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num <= 1)   //if number is negative then it is not prime
		return false;

	for (int i = 2; i < num; i++) { //divides number by 2 then increases until (number minus 1) and checks if there is a remainder
		if (num % i == 0)
			return false;
	}
	return true;  //if there is not a remainder after the loop then it is prime 
}

int main() {
	int input = 0; //variables for the integer input and the boolean result
	bool result = false;

	cout << "Please enter an integer to see if it is prime:" << endl; //ask for input
	cin >> input;

	while (cin.fail()) { //this checks to see if input is valid and will continue to loop until a valid input is entered
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid integer: " << endl;
		cin >> input;
	}

	result = isPrime(input); //call the function with the input to see if it is prime

	if (result) //print the resulting message on if it is prime or not
		cout << "This number (" << input << ") is a prime number!" << endl;
	else
		cout << "This number (" << input << ") is NOT a prime number!" << endl;

}