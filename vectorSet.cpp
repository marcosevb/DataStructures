#include <iostream>
#include <vector>
using namespace std;

bool isSet(const vector <int>& v) { //determines if a vector is a set

	for (int i = 0; i < v.size(); i++) {   //this loop goes through each number in the vector and stores it
		
		for (int j = 0; j < v.size() ; j++) { //this looks for a duplicate value in the vector
			if (i == j) //this excludes the same number at same index
				break;
			else if (v[i] == v[j])
				return false;
		}
	}
	return true; //if no duplicate is found then the vector is a set
}

void printSet(bool val) { //prints a message based on bool value if a vector is a set or not
	if (val)
		cout << "This vector is a Set!" << endl;
	else
		cout << "This vector is not a Set!" << endl;
}

void printVector(const vector <int>& v) { //prints a vector
	cout << "{ ";
	for (auto i : v)
		cout << i << ", ";
	cout << "}" << endl;
}

vector <int> setUnion(const vector <int>& v1, const vector <int>& v2) { //finds the union between two sets
	vector<int> result;

	if (v1 == v2) //checks if vectors are the same
		return v1;

	for (int i = 0; i < v1.size(); i++) //adds all members of first vector
		result.push_back(v1[i]);

	for (int i = 0; i < v2.size(); i++) { //compares all elements of second vector with all elements of first vector
		bool unique = true;
		for (int j = 0; j < v1.size(); j++) {
			if (v2[i] == v1[j])
				unique = false; //if there is a duplicate then not unique
		}
		if (unique) //if it is only in the second array then add it to result
			result.push_back(v2[i]);
	}

	return result;
}

vector <int> setIntersection(const vector <int>& v1, const vector <int>& v2) { //find the intersection of two sets
	vector<int> result;

	if (v1 == v2) //checks if vectors are the same
		return result;

	for (int i = 0; i < v1.size(); i++) {//compares all elements of first vector with all elements of second vector
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j])
				result.push_back(v1[i]); //if there is intersection then add it to the resulting vector
		}
	}

	return result;
}

vector <int> setDifference(const vector <int>& v1, const vector <int>& v2) {//find the difference between sets
	vector<int> result;

	if (v1 == v2) //checks if vectors are the same
		return result;
	
	for (int i = 0; i < v1.size(); i++) { //compares all elements of first vector with all elements of second vector
		bool unique = true;
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j])
				unique = false; //if there is a duplicate then not unique
		}
		if (unique) //if it is only in the first array then add it to result
			result.push_back(v1[i]);
	}

	return result; 
}

int main() {
	vector <int> v1 = {1,4,5,6,9};
	vector <int> v2 = {1,4,5,6,1};

	printVector(v1);
	printSet(isSet(v1));
	printVector(v2);
	printSet(isSet(v2));
	cout << endl;

	vector <int> v3 = {1,2,3,4};
	vector <int> v4 = {2,4,5,6};
	
	printVector(v3);
	printVector(v4);

	cout << "The union of these vectors is ";
	printVector(setUnion(v3, v4));
	cout << "The intersection of these vectors is ";
	printVector(setIntersection(v3, v4));
	cout << "The difference of the first and second vector is ";
	printVector(setDifference(v3, v4));
	cout << "The difference of the second and first vector is ";
	printVector(setDifference(v4, v3));
}