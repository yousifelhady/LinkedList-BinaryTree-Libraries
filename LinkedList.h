#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node * next;

public:
	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node (int d)
	{
		data = d;
		next = nullptr;
	}
	void Set_Data (int d) //set data of node
	{
		data = d;
	}
	int Get_Data () //get data of node
	{
		return data;
	}
	void Set_Next (Node* n) //set next node
	{
		next = n;
	}
	Node* Get_Next () //get next node
	{
		return next;
	}
	friend class LinkedList;
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	bool isEmpty()
	{
		if(head == nullptr)
			return true;
		return false;
	}
	void AddFront(int item)
	{
		Node * nw = new Node(item); //creating new node
		nw->Set_Next(head); //moving current head to next node OR use "nw->next = head"
		head = nw; //setting nw as a head
	}
	void RemoveFront()
	{
		if(isEmpty())
			return;
		Node * tmp = head;
		head = head->Get_Next(); //moving current head to next node OR use "head = head->next"
		delete tmp; //deleting old head i.e: deleting from list
	}
	void AddEnd(int item)
	{
		if(isEmpty())
			AddFront(item); //if empty list, add the new item at the front
		else
		{
			Node * tmp = head; //creating tmp node pointer
			while (tmp->next != nullptr)
			{
				tmp = tmp->next; //looping on the list till we get the last node
			}
			Node * nw = new Node(item); //creating new node
			tmp->next = nw; //adding the new node to the end of list
		}
	}
	void RemoveEnd()
	{
		if (isEmpty())
			return;
		if (head->next == nullptr)
		{
			RemoveFront();
			return;
		}
		Node * tmp1 = head; //hold the node before the last node
		Node * tmp2 = head->next; //hold the last node

		while (tmp2->next != nullptr) //loop until we get the last 2 items in the list
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		tmp1->next = nullptr; //for the node before the last node, set its "next" to nullptr which means that this node become the last node and after that become NULL
		delete tmp2; //remove the last node
	}
	void AddIndex(int item, int index)
	{
		if (isEmpty() || index == 0)
		{
			AddFront(item);
			return;
		}
		Node * tmp = head;
		while (--index != 0) //decrease the index before entering the while loop to stop at the index of the item just before the item i will add
		{
			tmp = tmp->next; //move to next item until the condition of while is false
			if (tmp == nullptr) //if exceeded the given index, then return
				return;
		}
		Node * nw = new Node(item);
		nw->next = tmp->next; //linking the added item with the next item
		tmp->next = nw; //linking the added item with the previous item
	}
	void RemoveIndex(int index)
	{
		if (isEmpty())
		{
			return;
		}
		if (index == 0)
			RemoveFront();
		Node * tmp = head;
		while (--index != 0) //decrease the index before entering the while loop to stop at the index of the item just before the item i will remove
		{
			tmp = tmp->next; //move to next item until the condition of while is false
			if (tmp == nullptr) //if exceeded the given index, then return
				return;
		}
		Node * toberemoved = tmp->next; 
		tmp->next = toberemoved->next; //linking the item that lies before the removed one with the item that lies after the removed one
		delete toberemoved; //deleting the removed item
	}
	int FindItem(int item)	//return index of item in list
	{
		if (isEmpty())
		{
			cout <<"List is empty!"<<endl;
			return -1; //return -1 if the list is empty which means "Item is not found"
		}
		Node * tmp = head;
		int index = 0;
		while (tmp != nullptr) //loop on linkedlist items
		{
			if (tmp->data == item) //if node's data equals to item, therefore return +ve index which means "Item is found"
				return index;
			tmp = tmp->next; //if not found in current node, go to next node
			index ++;
		}
		return -1; //return -1 which means "Item is not found"
	}
	void RemoveItem(int item)
	{
		if(isEmpty())
		{
			return;
		}
		int index = FindItem(item);
		if (index >= 0)
			RemoveIndex(index);
	}
	void PrintList()
	{
		Node * tmp = head;
		while (tmp != nullptr)
		{
			if (tmp->next == nullptr)
			{
				cout << tmp->data;
				break;
			}
			else {
			cout << tmp->data << " -> ";
			tmp = tmp->next;
			}
		}
	}
	void PrintList_Recursive()
	{
		PrintNode_Recursive(head);
	}
	void PrintNode_Recursive (Node * n)
	{
		if (n == nullptr)	//base case for recursion
			return;
		cout << n->data << " -> ";
		PrintNode_Recursive(n->next);

		/*if (n != nullptr)
		{
			cout << n->data <<" -> ";
			PrintNode_Recursive(n->next);
		}*/
	}
	void clear()
	{
		while (head != nullptr)
			RemoveFront();
	}

	void BubbleSort()
	{
		if(isEmpty())
			return;
		if(head->next == nullptr)
			return;
		Node * stop = nullptr;
		while (stop != head->next)
		{
			Node * tmp = head;
			while (1) {
				if (tmp->next == stop)
				{
					stop = tmp;
					break;
				}
				if (tmp->data > tmp->next->data)
				{
					//swap
					int v = tmp->data;
					tmp->data = tmp->next->data;
					tmp->next->data = v;
				}
				tmp = tmp->next;
			}
		}
	}

	void SelectionSort_Max2Min()
	{
		if(isEmpty())
			return;
		if(head->next == nullptr)
			return;
		Node * stop = nullptr;
		while (stop != head->next)
		{
			Node * max = head;
			Node * tmp = head->next;
			while (1)
			{
				if (tmp->data > max->data)
				{
					max = tmp;
				}
				if (tmp->next == stop)
				{
					stop = tmp;
					break;
				}
				tmp = tmp->next;
			}
			//swapping
			int v = tmp->data;
			tmp->data = max->data;
			max->data = v;
		}
	}

	void SelectionSort_Min2Max()
	{
		if(isEmpty())
			return;
		if(head->next == nullptr)
			return;
		Node * start = head;

		while (start->next != nullptr)
		{
			Node * min = start;
			Node * tmp = start->next;
			while (tmp != nullptr)
			{
				if (tmp->data < min->data)
				{
					min = tmp;
				}
				tmp = tmp->next;
			}
			//swapping
			int v = start->data;
			start->data = min->data;
			min->data = v;
			start = start->next;
		}
	}
};