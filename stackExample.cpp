//stack application

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

//stack operations
//push
//pop
//top
//size()
//empty()

template <class T> class myStack {
	vector<T> _v;

public:
	myStack() = default;

	void push(T t) {
		_v.push_back(t);
	}

	void pop() {
		_v.pop_back();
	}

	T& top() { //stack is like a stack of plates you always take the top
		return _v.back();
	}

	const T& top() const{
		return _v.back();
	}

	size_t size() const {
		return _v.size();
	}

	bool empty() const {
		return _v.empty();
	}
};

template <class T> class MyStackLL {

private:
	list<T> _list;

public:
	MyStackLL() = default;

	void push(T t) {
		_list.push_front(t);
	}

	void pop() {
		_list.pop_front();
	}

	T& top () {
		return _list.front();
	}

	const T& top() const {
		return _list.front();
	}

	size_t size() const {
		return _list.size();
	}

	bool empty() const {
		return _list.empty();
	}

};


bool isPalindrome(const string& str) {
	myStack<char> st;

	for (auto ch : str)
		st.push(ch);

	string reversed = "";
	while (!st.empty()) {
		reversed += st.top();
		st.pop();
	}

	return str == reversed;
}

bool isBalanced(const string& str) {
	MyStackLL<char> st;

	for (auto ch : str) {
		if (ch == '(') {
			st.push(ch);
		}
		else {
			if (!st.empty()) {
				st.pop();
			}
			else {
				return false;
			}
		}

	}

	return st.empty();
}

int main() {

	string s1 = "madamimadam";
	string s2 = "marcos";
	string s3 = "racecar";

	cout << "Are these string palindromes?" << endl;
	cout << s1 << ": " << boolalpha << isPalindrome(s1) << endl;
	cout << s2 << ": " << boolalpha << isPalindrome(s2) << endl;
	cout << s3 << ": " << boolalpha << isPalindrome(s3) << endl;

	string s4 = "()()(())";
	string s5 = "()(()";
	string s6 = "()))";

	cout << endl << "Are these set of parentheses balanced?" << endl;
	cout << s4 << " - " << boolalpha << isBalanced(s4) << endl;
	cout << s5 << " - " << boolalpha << isBalanced(s5) << endl;
	cout << s6 << " - " << boolalpha << isBalanced(s6) << endl;

}