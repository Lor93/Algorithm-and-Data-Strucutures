#include <iostream>
using namespace std;

class BST {
protected:
	struct Node {
		int data;
		Node* leftChild;
		Node* rightChild;

		Node() : data(0), leftChild(nullptr), rightChild(nullptr) {}
		Node(int data) : data(data), leftChild(nullptr), rightChild(nullptr) {}
		Node(int data, Node* leftChild, Node* rightChild) :
			data(data), leftChild(leftChild), rightChild(rightChild) {}
	};
public:
	BST() : root(nullptr) {}

	void insert(int data);
	Node* getRoot() { return root; }
	void printPost(Node* root);
	int Largest(Node* root);
	bool FindNode(Node* root, int data);
private:
	Node* root;
};
void BST::insert(int data) {
	if (root == nullptr) {
		root = new Node(data);
	}
	else {
		Node* newnode = new Node(data);
		Node* current = root;

		while (current != nullptr) {
			if (data < current->data) {
				if (current->leftChild == nullptr) {
					current->leftChild = newnode;
					break;
				}
				current = current->leftChild;
			}
			else {
				if (current->rightChild == nullptr) {
					current->rightChild = newnode;
					break;
				}
				current = current->rightChild;
			}
		}
		if (data < current->data)
			current->leftChild = newnode;
		else
			current->rightChild = newnode;

		}
}int BST::Largest(Node* root)
{
	Node* current = root;
	while (current->rightChild != NULL)
	{
		current = current->rightChild;
	}
	return(current->data);
}
bool BST::FindNode(Node* root, int data)
{
	if (root == NULL || root->data == data)
		return root;
	if (root->data < data)
		return FindNode(root->rightChild, data);
	return FindNode(root->leftChild, data);
}
void BST::printPost(Node* root)
{
	if (root == NULL)
		return;
	printPost(root->leftChild);
	printPost(root->rightChild);
	cout << root->data << " ";
}

int main() {
	BST tree;

	tree.insert(7);
	tree.insert(20);
	tree.insert(8);
	tree.insert(9);
	tree.insert(6);
	tree.insert(1);
	tree.insert(19);
	tree.insert(15);
	tree.insert(2);
	tree.insert(10);
	tree.printPost(tree.getRoot());
	cout << endl;
	cout << (tree.FindNode(tree.getRoot(),12) ? "FOUND":"NOT FOUND");
	cout << endl;
	cout << (tree.FindNode(tree.getRoot(),15) ? "FOUND":"NOT FOUND");
	cout << endl;
	cout << tree.Largest(tree.getRoot());
	return 0;
}

