#include "HashTable.h"

int main()
{
	//Create a few of nodes. 
	Node * one = new Node{ "Book", NULL };
	Node * two = new Node{ "Waterfall", NULL };
	Node * three = new Node{ "Cat", NULL };
	Node * four = new Node{ "Bee", NULL };
	Node * five = new Node{ "Coffee", NULL };
	Node * six = new Node{ "Ubuntu", NULL };
	Node * seven = new Node{ "Chocolate", NULL };
	Node * eight = new Node{ "Person", NULL };
	Node * nine = new Node{ "Tornado", NULL };
	Node * ten = new Node{ "Water", NULL };
	Node * eleven = new  Node{ "Sky", NULL }; 
	Node * twelve = new Node{ "Numbers", NULL }; 
	
	//Create a hash table object.
	HashTable myHashTable;

	//Insert some nodes into hash table object. 
	myHashTable.insertNodeHead(one);
	myHashTable.insertNodeHead(two);
	myHashTable.insertNodeHead(three);
	myHashTable.printTable();

	//Remove a specific node with key value. 
	myHashTable.removeNode("Cat");
	myHashTable.printTable();

	//Insert a few more nodes. 
	myHashTable.insertNodeTail(four);
	myHashTable.insertNodeHead(five);
	myHashTable.insertNodeHead(six);
	myHashTable.insertNodeHead(seven);
	myHashTable.insertNodeHead(eight);
	myHashTable.insertNodeHead(nine);
	myHashTable.insertNodeHead(ten);

	myHashTable.printTable();

	//Get a specific node in the hash table object. 
	Node * result = myHashTable.getNodeByKey("Tornado");

	if (result)
		cout << result->key << endl;
	else
		cout << "This node does not exist!" << endl; 
	
	return 0;
}

