#include "LinkedList.h"

// Constructs the empty linked list object.
LinkedList::LinkedList()
{
	head = new Node;  
	head->next = NULL;
	length = 0;
}

// Inserts an Node at the end of the list.
void LinkedList::insertNodeTail(Node * newNode)
{	
	Node * foo = head;
	Node * bar = head;
	while (bar)				//as long as there is a next node in linked list, keep looping
	{
		foo = bar;
		bar = foo->next;
	}
	foo->next = newNode;	//insert the node 
	newNode->next = NULL;	//set the next node to the inserted node at NULL 
	length++;

}

// Inserts a Node at the beginning of the list.
void LinkedList::insertNodeHead(Node * newNode){
	if (head->next)					//If the list is not empty	
	{			
		Node * foo = head->next;	//Take the next node to the head and store it. 
		head->next = newNode;		//The new node will become the node next to the head.
		newNode->next = foo;		//The stored node will be the next after the added node. 
	}
	else							//If the list is empty
	{
		head->next = newNode; 
		newNode->next = NULL; 
	}
	length++; 
}

// Removes a node from the list by node key.
bool LinkedList::removeNode(string nodeKey)
{
	if (!head->next) return false;			//List is empty, nothing to remove.
	Node * foo = head;
	Node * bar = head;
	while (bar)								//Loop over the linked list.
	{
		if (bar->key == nodeKey)			//If the element is found
		{
			foo->next = bar->next;			//The next element of the element we delete becomes the next element of foo
			delete bar;
			length--;
			return true;
		}
		foo = bar;
		bar = foo->next;
	}
	return false;							//The element was not found it can't be deleted, return false
}

// Searches for an Node by its key.
Node * LinkedList::getNode(string nodeKey)
{
	Node * foo = head;
	Node * bar = head;
	while (bar)
	{
		foo = bar;
		if ((foo != head) && (foo->key == nodeKey))
			return foo;									// Returns a reference to first match.
		bar = foo->next;
	}
	return NULL;										// Returns a NULL pointer if no match is found.
}

// Displays list contents to the console window.
void LinkedList::printList()
{
	if (length == 0)
	{
		cout << "\n{ }\n";
		return;
	}
	Node * foo = head;
	Node * bar = head;
	cout << "\n{ ";
	while (bar)
	{
		foo = bar;
		if (foo != head)
		{
			cout << foo->key;
			if (foo->next) cout << ", ";
			else cout << " ";
		}
		bar = foo->next;
	}
	cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
	return length;
}

// De-allocates list memory when the program ends.
LinkedList::~LinkedList()
{
	Node * foo = head;
	Node * bar = head;
	while (bar)
	{
		foo = bar;
		bar = foo->next;
		if (bar) delete foo;
	}
}