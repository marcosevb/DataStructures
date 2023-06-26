#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct Node { //This is the struct for the huffman tree node
	char ch;
	int freq{0};
	Node* left{ nullptr };
	Node* right{ nullptr };

	Node(char character, int frequency) : ch{ character }, freq{ frequency } {}; //constructor

	friend ostream& operator << (ostream& o, const Node& n) { //overload operators so the highest frequencies have the shortest encodings
		o << n.ch << ": " << n.freq;
		return o;
	}

	friend bool operator < (const Node& n1, const Node& n2) { //overload operators so the highest frequencies have the shortest encodings
		return n1.freq > n2.freq;
	}
};

struct CompareNode { //overload operators so the highest frequencies have the shortest encodings
	bool operator()(Node* pn1, Node* pn2) {
		return pn1->freq > pn2->freq;
	}
};

unordered_map<char,int> fileReading(string filename) {
	ifstream file(filename); //open up the file and print error message if you cannot
	if (!file.is_open()) {
		cerr << "Unable to open the file." << endl;
	}

	char ch;
	unordered_map<char, int> um;

	while (file.get(ch)) { //read each character from the file and get frequency
		um[ch] += 1;
	}

	file.close(); //close file and return unordered map
	return um;
}

void getEncode(Node* node, const string& str, unordered_map<char, string>& um) {// function which encodes each node starting from the root
	if (node == nullptr) {
		return;
	}

	if (node && node->left == nullptr && node->right == nullptr) {
		cout << node->ch << ": " << str << endl; //displays the char and its encoding
		um[node->ch] = str; //stores the value in an unordered map
		return;
	}

	getEncode(node->left, str + "0",um); //recursively assign values for encoding left is 0 and right is 1
	getEncode(node->right, str + "1",um);
}

void fileWriting(string filename, unordered_map<char, string> um) {
	ifstream input(filename); //open up the file and print error message if you cannot
	if (!input.is_open()) {
		cerr << "Unable to open the file." << endl;
	}

	ofstream output("pride.huff"); //make output file which will hold encoding

	char ch;
	while (input.get(ch)) { //read each char and then output the encoding to the file
		output << um[ch];
	}

	input.close(); //close both files
	output.close();
}

void encodingWriting(unordered_map<char, string> um) {
	ofstream output("huff.sch"); //make output file which will hold encoding

	for (auto ch : um) { //read each char and then output the encoding to the file
		output << ch.first << ch.second << endl;
	}

	output.close();
}

int main() {

	unordered_map<char, int> charsAndFrequency = fileReading("Pride_and_Prejudice.txt"); //declare unordered map with frequencues and call function to read file

	priority_queue<Node*, vector<Node*>, CompareNode> pq; //a priority queue will be used to support the construciton of the huffman tree

	for (auto& it : charsAndFrequency) { //first we add all the nodes with their char and freq
		pq.push(new Node(it.first, it.second));
	}

	while (pq.size() != 1) { //then we will contruction the huffman tree by making the size of the pq = 1
		auto node1 = pq.top();
		pq.pop();
		auto node2 = pq.top();
		pq.pop();

		Node* parent = new Node ('@', node1->freq + node2->freq); //makes the parent node with the children as left and right pointer
		parent->left = node1;
		parent->right = node2;
		pq.push(parent);
	}

	auto root = pq.top(); //the root is the pq only element when we finish the last loop
	unordered_map<char, string> charsAndEncoding;
	getEncode(root, "", charsAndEncoding); //now we will find the encoding for the huffman tree and store it in an unordered map

	fileWriting("Pride_and_Prejudice.txt", charsAndEncoding); //call the function to output encoding of input file to output file

	encodingWriting(charsAndEncoding);

}