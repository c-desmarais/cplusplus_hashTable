#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;


//Singly linked list
struct Node
{
	string key;
	Node * next;
};


class LinkedList 
{
	private:
		Node * head; // Head points to a list of data nodes.
		int length;  // Linked lists store a variable number of Nodes.

	public:
		LinkedList();
		void insertNodeTail(Node * newNode);						// Inserts a Node at the end of the list.
		void insertNodeHead(Node * newNode);						// Inserts a Node at the beginning of the list.
		bool removeNode(string nodeKey);							// Removes a Node from the list with node key. 
		Node * getNode(string nodeKey);
		void printList();
		int getLength();
		~LinkedList();												// De-allocates Linked List memory when the program ends.
};

#endif
