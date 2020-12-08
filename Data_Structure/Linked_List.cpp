#include <typeinfo>
#include <iostream>

using namespace std;

template <typename Type>
class Node
{
public:
	Type data;
	Node<Type> *next = NULL;
};

template <typename Type>
class LinkedList
{
public:
	// Constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Get the value located at index
	Type Get(const int index);

	// Add val at head
	void AddAtHead(const Type& val);

	// Add val at index
	void AddAtIndex(const int index, const Type& val);

	// Delete an element located at index
	void DeleteAtIndex(const int index);

	// Delete val in linked list
	void DeleteValue(const Type& val);

	// Move the first element of val to head
	void MoveToHead(const Type& val);

	// Rotate the linked list right by steps times
	void Rotate(const int steps);

	// Reduce value that repeats multiple times
	void Reduce();

	// reverse at every k number of nodes at a time
	void K_Reverse(const int k);

	// rearrage nodes to zig-zag manner
	void ZigZagRearrange();

	// Return the number of elements in the linked list
	int Size();

	// Delete all elements from the linked list
	void CleanUp();

	// Print the list
	void Print();

private:
	Node<Type> *head;
};

/*
 *	Implementation
 */

template <typename Type>
LinkedList<Type>::LinkedList()
	: head(NULL) {}


template <typename Type>
LinkedList<Type>::~LinkedList()
{
	CleanUp();
}

template <typename Type>
Type LinkedList<Type>::Get(const int index)
{
	Node<Type> *GetNode = head;

	if(index < 0 || index > Size()-1)
		return -1;
	else
	{
		for(int a = 0; a < index; a++)
			GetNode = GetNode->next;
	}
	return GetNode->data;
}

template <typename Type>
void LinkedList<Type>::AddAtHead(const Type& val)
{
	Node<Type> *AddNode = new Node<Type>;

	if(head == NULL)
	{
		AddNode->data = val;
		head = AddNode;
		AddNode->next = NULL;
	}
	else
	{
		AddNode->data = val;
		AddNode->next = head;
		head = AddNode;
	}
}

template <typename Type>
void LinkedList<Type>::AddAtIndex(const int index, const Type& val)
{
	Node<Type> *Letsgo = head;
	Node<Type> *InsertNode = new Node<Type>;
	int sizes = Size();

	if(index < 0 || index > sizes)
		return;
	else if(index == 0)
		AddAtHead(val);
	else if(index == sizes)
	{
		for(int a = 0; a < sizes - 1; a++)
			Letsgo = Letsgo->next;
		InsertNode->data = val;
		Letsgo->next = InsertNode;
		InsertNode->next = NULL;
	}
	else
	{
		for(int a = 0; a < index - 1; a++)
			Letsgo = Letsgo->next;
		InsertNode->data = val;
		InsertNode->next = Letsgo->next;
		Letsgo->next = InsertNode;
	}
}

template <typename Type>
void LinkedList<Type>::DeleteAtIndex(const int index)
{
	Node<Type> *DeleteNode = head;
	int sizes = Size();

	if(index < 0 || index > sizes-1)
		return;
	else if(index == 0)
	{
		head = DeleteNode->next;
	}
	else if(index == sizes-1)
	{
		for(int a = 0; a < sizes-2; a++)
			DeleteNode = DeleteNode->next;
		 DeleteNode->next = NULL;
	}
	else
	{
		for(int a = 0; a < index-1; a++)
			DeleteNode = DeleteNode->next;
		DeleteNode->next = DeleteNode->next->next;
	}

}

template <typename Type>
void LinkedList<Type>::DeleteValue(const Type& val)
{
	Node<Type> *DelNode;
	int Dval = 0;

	for(DelNode = head; DelNode != NULL; DelNode = DelNode->next)
	{
		if(DelNode->data == val)
		{
			DeleteAtIndex(Dval);
			break;
		}
		Dval++;
	}
}

template <typename Type>
void LinkedList<Type>::MoveToHead(const Type& val)
{
	Node<Type> *MoveNode;
	int Mval = 0;

	for(MoveNode = head; MoveNode != NULL; MoveNode = MoveNode->next)
	{
		if(MoveNode->data == val)
		{
			DeleteAtIndex(Mval);
			AddAtHead(val);
			break;
		}
		Mval++;
	}
}

template <typename Type>
void LinkedList<Type>::Rotate(const int steps)
{
	Node<Type> *RotNode = head;
	int sizes = Size();
	int headval;

	if(steps < 0) return;

	for(int a = 0; a < steps; a++)
	{
		headval = Get(sizes-1);
		DeleteAtIndex(sizes-1);
		AddAtHead(headval);
	}
}

template <typename Type>
void LinkedList<Type>::Reduce()
{
	Node<Type> *ReNode1 = head;
	Node<Type> *ReNode2;
	int sizes = Size();
	int check;

	for(int a = 0; a < sizes; a++)
	{
		check = 0;
		ReNode2 = head;
		for(int b = 0; b < a; b++)
		{
			if(ReNode2->data == ReNode1->data)
				{
					ReNode1 = ReNode1->next;
					check = 1;
					sizes = sizes-1;
					DeleteAtIndex(a);
					a--;
					break;
				}
			ReNode2 = ReNode2->next;
		}
		if(check != 1)
		ReNode1 = ReNode1->next;
	}
}

template <typename Type>
void LinkedList<Type>::K_Reverse(const int k)
{
	Node<Type> *point = head;
	Node<Type> *Rev;
	Node<Type> *temp;
	int sizes = Size();

	for(int a = 0; a < sizes/k; a++)
	{
		Rev = point;
		for(int b = 0; b < k; b++)
			Rev = Rev->next;

		if(a == sizes/k - 1)
		{
			for(int c = 0; c < k; c++)
			{
				temp = Rev;
				Rev = point;
				point = point->next;
				Rev->next = temp;
			}
			if(a == 0) head = Rev;
		}
		else
		{
			for(int d = 0; d < k; d++)
			{
				temp = Rev;
				Rev = point;
				point = point->next;
				if(d == 0)
				{
					for(int e = 0; e < k-1; e++)
						temp = temp->next;
					Rev->next = temp;
				}
				else Rev->next = temp;
			}
			if(a == 0) head = Rev;
		}
	}
}

template <typename Type>
void LinkedList<Type>::ZigZagRearrange()
{
	int sizes = Size();
	for(int a = 0; a < (sizes/2)-1; a++)
	{
		int k = Get(sizes/2 + a);
		DeleteAtIndex(sizes/2 + a);
		AddAtIndex(2*a+1, k);
	}
}

template <typename Type>
int LinkedList<Type>::Size()
{
	Node<Type> *counter;
	int count = 0;
	for(counter = head; counter != NULL; counter = counter->next)
		count++;

	return count;
}

template <typename Type>
void LinkedList<Type>::CleanUp()
{
	int sizes = Size();
	for(int a = 0; a < sizes; a++)
		DeleteAtIndex(0);
}

template <typename Type>
void LinkedList<Type>::Print()
{
	Node<Type> *printer = head;
	int sizes = Size();
	cout << "(";
	for(int a = 0; a < sizes; a++)
	{
		cout << printer->data;
		if(a != sizes-1)
			cout << ",";
		printer = printer->next;
	}
	cout << ")" << endl;
}

int main()
{
	LinkedList<int> LL;
	for(int i = 0; i < 10; i++)
		LL.AddAtHead(i);
	LL.Print(); // (9,8,7,6,5,4,3,2,1,0)

	cout << LL.Get(2) << endl; //7

	LL.AddAtIndex(1,8);
	LL.Print(); // (9,8,8,7,6,5,4,3,2,1,0)

	LL.DeleteAtIndex(3);
	LL.Print(); // (9,8,8,6,5,4,3,2,1,0)

	LL.DeleteValue(9);
	LL.Print(); // (8,8,6,5,4,3,2,1,0)

	LL.MoveToHead(2);
	LL.Print(); // (2,8,8,6,5,4,3,1,0)

	LL.Rotate(2);
	LL.Print(); // (1,0,2,8,8,6,5,4,3)

	LL.AddAtHead(4);
	LL.Print(); // (4,1,0,2,8,8,6,5,4,3)

	LL.Reduce();
	LL.Print(); // (4,1,0,2,8,6,5,3)

	LL.AddAtIndex(7,10);
	LL.Print(); // (4,1,0,2,8,6,5,10,3)

	LL.ZigZagRearrange();
	LL.Print(); // (4,8,1,6,0,5,2,10,3)
	cout << LL.Size() << endl; // 9

	LL.K_Reverse(3);
	LL.Print(); // (1,8,4,5,0,6,3,10,2)
	cout << LL.Size() << endl; // 9

	LL.CleanUp();
	cout << LL.Size() << endl; // 0
}

