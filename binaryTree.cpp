#include <iostream>
using namespace std;

struct Node {
	int n;
	Node* left;
	Node* right;
	Node() = delete;
	Node(int n) : n(n), left{ nullptr }, right{ nullptr } {};
};

void inOrder(Node* node)
{
	if (node)
	{
		inOrder(node->left);
		cout << node->n << " ";
		inOrder(node->right);
	}
}

void postOrder(Node* node)
{
	if (node)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->n << " ";
	}
}

void preOrder(Node* node)
{
	if (node)
	{
		cout << node->n << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

int main()
{
	Node* tree = new Node(1);
	tree->left = new Node(7);
	tree->right = new Node(9);
	tree->left->left = new Node(2);
	tree->left->right = new Node(6);

	preOrder(tree);
	cout << "(PreOrder)" << endl;
	inOrder(tree);
	cout << "(InOrder)" << endl;
	postOrder(tree);
	cout << "(PostOrder)" << endl;
}
