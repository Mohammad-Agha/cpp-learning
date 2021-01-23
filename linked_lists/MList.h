#pragma once

struct node
{
	int data;
	node* next = nullptr;
};

class MList
{
public:
	// Default Constructor
	MList();
	
	// Destructor
	~MList();

	// Prints the values of the linked list nodes
	void PrintValues();

	// Returns the number of nodes of the linked list
	int Length();

	// Returns true if the linked list is empty
	bool isEmpty();

	// Get the value at the nth item of the linked list starting from 0;
	int ValueAt(int index);

	// Add a node the end of the linked list
	void PushEnd(int value);

	// Add a node the start of the linked list
	void PushStart(int value);

	// Insert a value at a certain index 
	void PushAt(int index, int value);
	
	// Removes the first node and returns its value
	int PopStart();

	// Removes the last node and returns its value
	int PopEnd();

	// Remove a node a certain index 
	int PopAt(int index);

	// Remove the first node holding the given value
	void PopValue(int value);

	// Get the value of the first element
	int FirstElement();

	// Get the value of the last element
	int LastElement();
	
	// Returns tha value of the node at the nth value from the last nod 
	int ValueAtBack(int index);

	// Reverses the linked list
	void Reverse();


private:
	node* head;
};
