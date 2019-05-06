#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

class Leaf
{
public:
	int data;
	Leaf* left;
	Leaf* right;	
	
	Leaf(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	Leaf* createLeaf(int data);
	Leaf* insertData(Leaf* root, int data);
	void preOrderTraversal(Leaf* root);
	void inOrderTraversal(Leaf* root);
	void postOrderTraversal(Leaf* root);
	void levelOrderTraversal(Leaf* root);
};

Leaf* BST :: createLeaf(int data)
{
	Leaf* newLeaf = new Leaf(data);
	return newLeaf;
}

Leaf* BST ::  insertData(Leaf* root, int data)
{
	BST tree;
	Leaf* newLeaf = tree.createLeaf(data);
	if(root == NULL)
	{
		root = newLeaf;
	}
	else
	{
		Leaf* tempRoot = root;
		while(1)
		{
			if(data < tempRoot->data)
			{
				if(tempRoot->left == NULL)
				{
					tempRoot->left = newLeaf;
					break;
				}
				tempRoot = tempRoot->left;
			}
			else if(data > tempRoot->data)
			{
				if(tempRoot->right == NULL)
				{
					tempRoot->right = newLeaf;
					break;
				}
				tempRoot = tempRoot->right;
			}
		}
	}
	return root;
}

void BST :: preOrderTraversal(Leaf* root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void BST :: inOrderTraversal(Leaf* root)
{
	if(root != NULL)
	{
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}

void BST :: postOrderTraversal(Leaf* root)
{
	if(root != NULL)
	{
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->data << " ";
	}
}

void BST :: levelOrderTraversal(Leaf* root)
{
	queue<Leaf*> tempQ;
	tempQ.push(root);
	while(!tempQ.empty())
	{
		Leaf* temp = tempQ.front();
		tempQ.pop();
		cout << temp->data << " ";
		if(temp->left != NULL)
			tempQ.push(temp->left);
		if(temp->right != NULL)
			tempQ.push(temp->right);
	}
}

int main()
{
	int data, choice;
	Leaf* root = NULL;
	BST tree;
	while(1)
	{
		cout << "1-> Insert data to BST" << endl;
		cout << "2-> Display binary search tree" << endl;
		cout << "0-> Exit menu" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Enter a data to insert: ";
				cin >> data;
				root = tree.insertData(root, data);
				cout << data << " is inserted successfully" << endl << endl;
				break;
			case 2:
				if(root != NULL)
				{
					cout << "Pre-order traversal display:" << endl;
					tree.preOrderTraversal(root);
					cout << endl << "In-order traversal display:" << endl;
					tree.inOrderTraversal(root);
					cout << endl << "Post-order traversal display:" << endl;
					tree.postOrderTraversal(root);
					cout << endl << "Level-order traversal display:" << endl;
					tree.levelOrderTraversal(root);
				}
				else
				{
					cout << "Tree is empty. Nothing to display" << endl;
				}
				cout << endl << endl;
				break;
			case 0:
				exit(0);
			default:
				cout << "Error: Wrong entry. Enter again." << endl;
				break;
		}
	}
	return 0;
}
