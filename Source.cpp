#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <list>
#include "LinkedList.h"
#include "Tree.h"

int isRepreated_unsorted (int ar[], int n)
{
	for (int i = 0 ; i < n-1 ; i++)
	{
		for (int j = i + 1 ; j < n ; j++)
		{
			if (ar[i] == ar[j])
				return 1;
		}
	}
	return 0;
}

int isRepreated_sorted (int ar[], int n)
{
	for (int i = 0 ; i < n ; i++)
	{
		if (ar[i] == ar[i+1])
		return 1; //when an item is repeated
	}
	return 0; //when all items are not repeated
}

int GetMax (int ar[], int n)	//get max element of an array
{
	if (n==1)
		return ar[0];
	int max;
	max = GetMax(ar, n-1);
	if (max < ar[n-1])
		max = ar[n-1];
	return max;
}

int factorial (int n)
{
	if (n==1 || n==0)
		return 1;
	int f;
	f = n * factorial(n-1);
	return f;
}

void MySwap (int &x, int &y)	//takes the original 'x' & 'y' value by reference
{
	int tmp1 = x;
	int tmp2 = y;
	x = tmp2;
	y = tmp1;
}

void bubbleSort (int ar[], int n)
{
	for (int j=0 ; j<n-1 ; j++)
	{
		bool sorted = true;
		for (int i=0 ; i<n-1-j ; i++)
		{
			if (ar[i] > ar[i+1]) {
				sorted = false;
				MySwap (ar[i], ar[i+1]);
			}
		}
		if (sorted)
			break;
	}
}

void selectionSort_Min2Max (int ar[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (ar[j] < ar[min]) {
				MySwap(ar[j], ar[min]);
			}
		}
	}
}

void selectionSort_Max2Min (int ar[], int n)
{
	for (int i = n-1; i >= 0; i--)
	{
		int max = i;
		for (int j = i-1; j >=0 ; j--)
		{
			if (ar[j] > ar[max]) {
				MySwap(ar[j], ar[max]);
			}
		}
	}
}

bool compareStacks (stack<int> &s1, stack<int> &s2)	//compare 2 stacks and return true if both are identaically the same
{
	stack<int> tmp;
	bool same = true;
	while(1)
	{
		if (s1.empty() && s2.empty())
			break;
		if ((s1.empty() && !s2.empty()) || (!s1.empty() && s2.empty()))
		{
			same = false;
			break;
		}
		int v1 = s1.top();
		int v2 = s2.top();
		if (v1 != v2)
		{
			same = false;
			break;
		}
		tmp.push(v1);
		s1.pop();
		s2.pop();
	}
	while (!tmp.empty())
	{
		int v = tmp.top();
		s1.push(v);
		s2.push(v);
		tmp.pop();
	}
	return same;
}

int peek (int arr[], int n)		//return last element in array
{
	for (int i = 0; i < n; i++)
	{
		if (i+1 == n)
			return arr[i];
	}
}

int RemoveRepeatedFromArray (int arr[], int n)
{
	stack<int> tmp;
	int newsize = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp.empty())
		{
			tmp.push(arr[i]);
			newsize++;
			continue;
		}
		if (tmp.top() == arr[i])
			continue;
		else
		{
			tmp.push(arr[i]);
			newsize++;
		}
		//arr[i] = 0;
	}
	for (int j = newsize-1 ; j >=0 ; j--)
	{
		arr[j] = tmp.top();
		tmp.pop();
	}
	return newsize;
}


/*
int ReverseNumber(int n)
{
	stack<string> TmpStack;
	string TmpString = to_string(n);
	int output;
	string y;
	for (int i = 0 ; i < TmpString.length() ; i++)
	{
		TmpStack.push(TmpString.substr(i,0));
	}
	for (int i = 0 ; i < TmpString.length() ; i++)
	{
		string x = TmpStack.top();
		TmpStack.pop();
		string y = "";
		y +=x;
	}
	output = stoi(y);
	return output;
}

int charexperession (char* expr)
{
	char x = *expr;
	int first, second;
	cin >> first >> second;
	int result = first + x + second;
	return result;
}
*/
class EmailAddrBook
{
private:
	string contacts[100];
	int	NoOfContacts;

public:
	EmailAddrBook() {
		NoOfContacts = 0;
	}
	string GetContact (int index) {
		return contacts[index];
	}
	void SetContact (string contact, int index) {
		contacts[index] = contact;
	}
	void AddContact (string newcontact) {
		contacts[NoOfContacts] = newcontact;
		NoOfContacts++;
	}
	int GetNoOfContacts () {
		return NoOfContacts;
	}
	void Print () {
		cout <<"Contacts\n";
		for (int i = 0; i < NoOfContacts; i++)
		{
			cout << i+1 << "- " << contacts[i] << endl;
		}
	}
};

int main ()
{
	/*int size;
	cin >> size;
	float *pf;
	pf = new float [size];
	float sum = 0;
	for (int i=0 ; i<size ; i++)
	{
		pf[i] = 1.0 / factorial(i);
		sum += pf[i];
	//	cout << pf[i] << endl;
	}
	cout <<"sum equals = " << sum ;
	delete [] pf; //don't forget to delete the pointers at the end of code!
	*/
	/*LinkedList l;

	l.AddEnd(2);
	l.AddEnd(4);
	l.AddEnd(7);
	l.AddEnd(1);
	l.BubbleSort();
	l.PrintList();
	*/
	int ar[15] = {10,5,2,6,15,1,80,75,44,22,12,3,8,11,9};
	/*selectionSort_Max2Min(ar, 8);
	for (int i = 0; i < 8; i++)
	{
		cout << ar[i] << endl;	
	}
	
	int x = RemoveRepeatedFromArray(ar, 15);
	for (int i = 0; i <x ; i++)
	{
		cout << ar[i] << endl;	
	}
	*/
	//creating dynamic array
	/*int *pi, size;
	cin >> size;
	pi = new int [size];
	for (int i = 0; i < size; i++)
	{
		pi[i] = i+1;
	}
	for (int i = 0; i < size; i++)
	{
		cout << pi[i] << endl;
	}
	*/

	/*stack<int> s1, s2;
	for (int i = 0; i < 10; i++)
	{
		s1.push(i+1);
		s2.push(i+1+1);
	}
	cout << compareStacks (s1, s2);
	*/
	/*
	queue<int> q;
	q.push(1);
	q.push(2);
	int z = q.back();
	cout << z;
	cout << endl;

	list<int> l;
	l.push_back(60);
	l.push_back(1);
	int y = l.front();
	l.pop_front();
	cout << y;
	*/

	Tree t;
	/*
	t.SortArray_BST (ar, 15);
	for (int i = 0; i < 15; i++)
	{
		cout << ar[i] << endl;	
	}
	*/
	t.insert(5);
	t.insert(2);
	t.insert(7);
	t.insert(3);
	t.insert(1);
	t.insert(8);
	t.insert(6);
	t.insert(9);
	t.insert(7);
	t.PrintTree(t.GetRoot());
	cout << endl << endl << endl << endl;
	cout << "No. of leaves: " << t.countLeaf(t.GetRoot()) << endl;
	cout << "No. of nodes: " << t.countNodes(t.GetRoot()) << endl;
	cout << "Min element: " << t.GetMin_BST(t.GetRoot()) << endl;
	cout << "Max element: " << t.GetMax_BST(t.GetRoot()) << endl;
	cout << "Enter the number you want to search for: " ;
	int x;
	cin >> x;
	cout << "Is " << x << " exists at tree? " << endl << "=> " << t.Find_BST(x) << endl;
	
	cout << endl;
	return 0;
}