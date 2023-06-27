#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& vi, int target) {
	int left = 0;
	int right = vi.size() - 1;
	int mid;

	while (left <= right) {
		mid = (right - left) / 2 + left;
		if (vi.at(mid) == target)
			return mid;
		else if (vi[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int recursiveBinarySearch(vector<int>& vi,int target, int left, int right) {

	if (left <= right) {
		int mid = (right - left) / 2 + left;
		if (vi.at(mid) == target)
			return mid;
		else if (vi[mid] < target)
			return recursiveBinarySearch(vi, target, mid + 1, right);
		else
			return recursiveBinarySearch(vi, target, left, mid - 1);
	}

	return -1;
}

int main() {
	int numbers[] = { 1,2,3,4,5,6,7 };

	for (int i : numbers) {
		cout << i << ", ";
	}
	cout << endl;

	vector<int> vi(numbers, numbers + size(numbers));

	int searchNum = 0;
	cout << "Please enter an integer to search for: " << endl;
	cin >> searchNum;

	int x = recursiveBinarySearch(vi, searchNum, 0, vi.size() - 1);

	cout << "(-1 means number not found) The index is: " << x << endl;
}