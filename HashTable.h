#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

class HashTable
{
	private:
		LinkedList * array;			// Array is a reference to an array of Linked Lists. The array stores a fixed number of linked lists. 
		int length;					// Length of the hash table array.
		int hash(string nodeKey);	// Returns an array location for a given node key.

	public:
		HashTable(int tableLength = 13);							//Default array length is 13. 
		void insertNodeTail(Node * newNode);						//Inserts a node at the end of the linked list. 
		void insertNodeHead(Node * newNode);						//Inserts a node at the beggining of the linked list.
		bool removeNode(string nodeKey);
		Node * getNodeByKey(string nodeKey);	// Returns a node from the Hash Table by key.
		void printTable();
		int getLength();			// Returns the number of locations in the Hash Table.
		int getNumberOfNodes();		// Returns the number of nodes in the Hash Table.
		~HashTable();				// De-allocates all memory used for the Hash Table.
};

#endif