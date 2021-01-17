#pragma once
#include <iostream>
class MVector
{
public:
	// Default constructor which intialized the vector's capacity to 16
	MVector();

	// Another constructor - Copy constructor
	MVector(const MVector& mv);

	// Another constructor - Initializer with value and size
	MVector(int length, int element);

	// Destructor which free the allocated memory
	~MVector();

	// Add an element at the end of the vector
	void Push(int value);

	// Add an element to the vector at a given index
	void PushAt(int value, int index);

	// Remove the last element of the vector and returns it
	int Pop();

	// Remove an element at a given index and returns it
	int PopAt(int index);

	// Get the value at a certain index
	int ValueAt(int index);

	// Get the first index of certain value, returns -1 if it's not present in the vector
	int IndexAt(int value);

	// Checks if the vector is empty
	bool isEmpty();

	// Returns the length of the vector
	int Length() const;

	// Returns the capacity of the vector
	int Capacity() const;

	// Add the ability to use [] notation for a MVector instance
	int operator[](int index);

	// Print the addresses of the elements of the vector
	void PrintAddresses();

	// Print the values of the vector
	void PrintValues();
	
private:
	int size;
	int capacity;
	int* arr;

	// Checks if two vectors are equal
	bool operator==(const MVector& mv);

	// Add the ability to use << 
	friend std::ostream& operator<<(std::ostream& out, const MVector& mv);

	// Vector growth - Reusable function that checks if the capacity should be doubled or not
	void IncreaseSize();

	// Vector shrink - Reusable function that checks if the capacity should be halved or not
	void DecreaseSize();
};