#include<iostream>
using namespace std;

//Definitions for the node of the Binary Search Tree
struct BinaryNode
{
	int data;
	BinaryNode* left;
	BinaryNode* right;
};

//Function to create a new node
BinaryNode* GetNewNode(int data)
{
	BinaryNode* newNode = new BinaryNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Returns the address of the root node at the end
BinaryNode* Insert(BinaryNode* root,int data)
{
	if (root == NULL)
	{
		//empty tree
		root = GetNewNode(data);
	}
	// if data is less, insert in left subtree. 
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	//if that is not the case, insert in right subtree. 
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

//returns true if the element is found
bool Find(BinaryNode* root,int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Find(root->left, data);
	}
	else
	{
		return Find(root->right, data);
	}
}

int main()
{
	//Creates an empty tree
	//test for the binary search tree
	BinaryNode* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	//ask the user to input a number
	int number;
	cout << "Please type a number to be searched\n";
	//allows the user to type in the command prompt
	cin >> number;
	//the command will say if the number is found
	if (Find(root, number) == true) cout << "Number was found\n";
	else cout << "Number was not found\n";
}