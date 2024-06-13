#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}

};
class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = nullptr; // initializing ROOT to null
	}
	void insert(string element) // insert a node in the+ binary search tree
	{
		Node* newNode = +new Node(element, nullptr, nullptr); //allocate memory for the new node
		newNode->info = element; //asign value to the data field of the new data
		newNode->leftchild = nullptr; //make the left child of the new node point to null
		newNode->rightchild = nullptr; //make the right child of the new data point to null

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); //locate the node which be the parent of the node to be inserted


		if (parent == nullptr) //if the parent is NULL (Tree is empty)
		{
			ROOT = newNode; //mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info) // If the value in the data field of the new node is less than that of the
		{
			parent->leftchild = newNode; // Make the left child of the parent point to the new node
		}
		else if (element > parent->info) // If the value in the data field of the new node is greater than that of the
		{
			parent->rightchild = newNode; // Make the right child of the parent point to the new node
		}
	}
	void search(string element, Node*& parent, Node*& currentNode)
	{
		// This Function searches the currentNode of the specified Node as well as the current Node of its per
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}


};


