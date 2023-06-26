#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
using namespace std;

unordered_map<string,char> fileReading(string filename) {
	ifstream file(filename); //open up the file and print error message if you cannot
	if (!file.is_open()) {
		cerr << "Unable to open the file." << endl;
	}

	char ch;
	string str;
	unordered_map<string,char> um;

	while (file.get(ch)) { //store the char first and the encoding bitstring as second
		getline(file,str);
		um[str] = ch;
	}

	file.close(); //close file and return unordered map
	return um;
}

void fileWriting(string filename, unordered_map<string, char> um) {
	ifstream input(filename); //open up the file and print error message if you cannot
	if (!input.is_open()) {
		cerr << "Unable to open the file." << endl;
	}

	ofstream output("pride_decoded.txt"); //make output file which will hold decoding

	char currentBit;
	string currentPattern = "";

	while (input.get(currentBit)) { //read each bit and add to current pattern
		currentPattern.push_back(currentBit);
		unordered_map<string, char>::iterator it = um.find(currentPattern); //this iterator looks in um to see if bitstring is an encoding
		if (it != um.end()) { //if the bitstring is recognized then output the char to the file
			output << it->second;
			currentPattern = ""; //restart pattern
		}
	}

	input.close(); //close both files
	output.close();
}

int main() {
	unordered_map<string, char> charsAndEncoding = fileReading("huff.sch"); //call function to store encoding in um

	fileWriting("pride.huff", charsAndEncoding); //call function to decode the file

	cout << "Check the location of this project for the decoded text file!" << endl;

}