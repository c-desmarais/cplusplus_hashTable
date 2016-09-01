#include "HashTable.h"

// Constructs the empty Hash Table object. Length is set to 13 by default.
HashTable::HashTable(int tableLength)
{
	if (tableLength <= 0) tableLength = 13; //Better to choose a prime nb for lenght to reduce collisions. 
	array = new LinkedList[tableLength];
	length = tableLength;
}

// Returns an array index for a given Node key.
int HashTable::hash(string nodeKey)
{
	int value = 0;
	for (size_t i = 0; i < nodeKey.length(); i++) // Using size_t is to get rid of signed/unsigned mismatch warning (C4018).
		value += nodeKey[i];
	return (value * nodeKey.length()) % length;
}

// Adds a Node to the Hash Table at the end of the corresponding linked list.
void HashTable::insertNodeTail(Node * newNode)
{
	int index = hash(newNode->key);
	array[index].insertNodeTail(newNode);
}

// Adds a Node to the Hash Table at the beginning of the corresponding linked list. 
void HashTable::insertNodeHead(Node * newNode)
{
	int index = hash(newNode->key);
	array[index].insertNodeHead(newNode);
}


// Deletes an Node by key from the Hash Table.
bool HashTable::removeNode(string nodeKey)
{
	int index = hash(nodeKey);
	return array[index].removeNode(nodeKey); //True when successfully removed. 
}

// Returns an Node from the Hash Table by key.
Node * HashTable::getNodeByKey(string nodeKey)
{
	int index = hash(nodeKey);
	return array[index].getNode(nodeKey); // If not found, returns null pointer. 
}

// Display the contents of the Hash Table to console window.
void HashTable::printTable()
{
	cout << "\n\nHash Table:\n";
	for (int i = 0; i < length; i++)
	{
		cout << "ArrayIndex " << i << ": ";
		array[i].printList();
	}
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
	return length;
}

// Returns the number of Nodes in the Hash Table.
int HashTable::getNumberOfNodes()
{
	int NodeCount = 0;
	for (int i = 0; i < length; i++)
	{
		NodeCount += array[i].getLength();
	}
	return NodeCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
	delete[] array;
}