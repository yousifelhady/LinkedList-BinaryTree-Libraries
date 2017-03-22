#include <iostream>
#include <iomanip> 
using namespace std;

class TreeNode
{
private:
	int data;
	TreeNode * left;
	TreeNode * right;
	friend class Tree;

public:
	TreeNode()
	{
		data = 0;
		left = nullptr;
		right = nullptr;
	}

	TreeNode(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}

	bool isLeaf()
	{
		if (left == nullptr && right == nullptr)
			return true;
		return false;
	}
};

class Tree //binary tree
{
private:
	TreeNode * root;

public:
	Tree()
	{
		root = nullptr;
	}

	TreeNode * GetRoot()
	{
		return root;
	}

	bool isEmpty()
	{
		if (root == nullptr)
			return true;
		return false;
	}

	int countLeaf(TreeNode * r)
	{
		if (r == nullptr)
			return 0;
		if (r->isLeaf())
			return 1;
		return countLeaf(r->left) + countLeaf(r->right);
	}

	int countNodes(TreeNode * r)
	{
		if (r == nullptr)
			return 0;
		if (r->isLeaf())
			return 1;
		return countNodes(r->left) + countNodes(r->right) +1;
	}

	int GetMin_BST(TreeNode * r)
	{
		//if (isEmpty()) return 0;
		while (r->left != nullptr)
			r = r->left;
		return r->data;
	}

	int GetMax_BST(TreeNode * r)
	{
		//if (isEmpty()) return 0;
		while (r->right != nullptr)
			r = r->right;
		return r->data;
	}
	
	bool Find_BST(int data)
	{
		if (isEmpty())
			return false;
		TreeNode * tmp = root;
		while (tmp != nullptr)
		{
			if (tmp->data == data)
			{
				return true;
			}
			else if (data < tmp->data)
				tmp = tmp->left;
			else if (data > tmp->data)
				tmp = tmp->right;
		}
		return false;
	}

	
	//

	void insert(int data)	//BST
	{
		if(!root)
		{
			 root = new TreeNode(data);  // Node constructor should receive
									 // the data value and init internal value from it
									 // it should also set left and right pointers to 0
			 return;
		}

		TreeNode* insertIterator = root;
		TreeNode* parent = nullptr;

		while(insertIterator != nullptr)
		{
			 parent = insertIterator;
			 insertIterator = (data < insertIterator->data)? insertIterator->left : insertIterator->right;
		}

		if (data < parent->data)
			 parent->left = new TreeNode(data);
		else
			 parent->right = new TreeNode(data);
	}

	void insert_BST(int data)
	{
		if (isEmpty())
		{
			root = new TreeNode(data);
			return;
		}
		TreeNode * parent = root;
		while (1)
		{
			if (data < parent->data)	//go left
			{
				if (parent->left != nullptr)
				{
					parent = parent->left;
				}
				else
				{
					parent->left = new TreeNode(data);
					break;
				}
			}
			if (data > parent->data)	//go right
			{
				if (parent->right != nullptr)
				{
					parent = parent->right;
				}
				else
				{
					parent->right = new TreeNode(data);
					break;
				}
			}
		}
	}

	void PrintTree(TreeNode * p, int indent=0)
	{
		if(p != NULL) {
			if(p->right) {
				PrintTree(p->right, indent+5);
				cout << endl;
			}
			if(p->left) PrintTree(p->left, indent+5);
			if (indent) {
				cout << setw(indent) << ' ';
			}
			cout<< p->data << "\n ";
		}
	}

	void PrintTree_(TreeNode * nNode, int pos) //not used
	{
		if (nNode==nullptr) {
			for(int i=0;i<pos;i++) cout<<"\t";
			cout<<"*";
			return;
		}
		PrintTree_(nNode->right, pos+1);
		for(int i=0;i<pos;i++) cout<<"\t";
		cout<<nNode->data;
		PrintTree_(nNode->left, pos+1);
	}

	void ArrayToTree (int * arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			insert_BST(arr[i]);
		}
	}

	void AddToArray (TreeNode * n, int * arr, int &index)	//in-order traverser
	{
		if (n == nullptr)
			return;
		if (n->isLeaf())
		{
			arr[index] = n->data;
			index ++;
		}
		else
		{
			AddToArray (n->left, arr, index);
			arr[index] = n->data;
			index ++;
			AddToArray (n->right, arr, index);
		}
	}

	void SortArray_BST (int * arr, int size)
	{
		ArrayToTree (arr, size);
		int index = 0;
		AddToArray (this->GetRoot(), arr, index);
	}
};