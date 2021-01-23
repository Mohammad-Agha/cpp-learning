#include "MList.h"
#include <iostream>
#include <stdexcept>

MList::MList() :
	head(nullptr)
{
}

MList::~MList()
{
	while (this->head != nullptr)
	{
		node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

void MList::PushEnd(int value)
{
	if (this->head == nullptr)
	{
		node* newNode = new node;
		newNode->data = value;
		newNode->next = nullptr;
		this->head = newNode;
		return;
	}
	node* temp = this->head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	node* newNode = new node;
	newNode->data = value;
	newNode->next = nullptr;
	temp->next = newNode;

}

void MList::PushStart(int value)
{
	node* newNode = new node;
	newNode->data = value;
	newNode->next = this->head;
	this->head = newNode;
}

int MList::PopStart()
{
	if (this->head == nullptr)
	{
		throw std::invalid_argument("List is empty");
	}
	int value = this->head->data;
	this->head = this->head->next;
	return value;
}

int MList::PopEnd()
{
	if (this->head == nullptr)
	{
		throw std::invalid_argument("List is empty");
	}
	if (this->head->next == nullptr)
	{
		int value = this->head->data;
		delete this->head;
		this->head = nullptr;
		return value;
	}
	node* current = this->head;
	node* prev = this->head;
	while (current->next != nullptr)
	{
		prev = current;
		current = current->next;
	}
	int value = current->data;
	delete current;
	prev->next = nullptr;
	return value;
}

int MList::PopAt(int index)
{
	if (index < 0 || this->head == nullptr)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	node* current = this->head;
	node* prev = this->head;
	int i;
	for (i = 0; i < index && current->next != nullptr; i++)
	{
		prev = current;
		current = current->next;
	}
	if (current->next == nullptr && i < index)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	if (i == 0) {
		return this->PopStart();
	}
	int value = current->data;
	prev->next = current->next;
	delete current;
	return value;
}

void MList::PopValue(int value)
{
	if (this->head == nullptr)
	{
		throw std::invalid_argument("List is empty");
	}
	if (this->head->data == value)
	{
		this->head = this->head->next;
		return;
	}
	node* current = this->head;
	node* prev = this->head;
	while (current != nullptr)
	{
		if (current->data == value)
		{
			prev->next = current->next;
			delete current;
			return;
		}
		prev = current;
		current = current->next;
	}
}

int MList::FirstElement()
{
	if (this->head == nullptr)
	{
		throw std::invalid_argument("List is empty");
	}
	return this->head->data;
}

int MList::LastElement()
{
	if (this->head == nullptr)
	{
		throw std::invalid_argument("List is empty");
	}
	node* temp = this->head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	return temp->data;
}

int MList::ValueAtBack(int index)
{
	if (index < 0)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	int size = this->Length();
	int position = size - index;
	if (position >= 0)
	{
		return this->ValueAt(position - 1);
	}
	throw std::invalid_argument("Index out of bounds");
}

void MList::PushAt(int index, int value)
{
	if (index < 0)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	if (this->head == nullptr && index > 0)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	if (this->head == nullptr)
	{
		this->PushStart(value);
		return;
	}
	if (index == 0)
	{
		this->PushStart(value);
		return;
	}
	node* temp = this->head;
	node* prev = temp;
	int i;
	for (i = 0; i < index && temp->next != nullptr; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	if (i + 1 < index)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	node* newNode = new node;
	newNode->data = value;
	if (temp->next == nullptr && i < index)
	{
		temp->next = newNode;
	} 
	else
	{	
		newNode->next = temp;
		prev->next = newNode;
	}
}

void MList::Reverse()
{
	node* prev = nullptr;
	node* next = nullptr;
	node* current = this->head;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	this->head = prev;
}

void MList::PrintValues()
{
	if (this->head == nullptr)
	{
		std::cout << "The list is empty";
		return;
	}
	node* temp = this->head;
	while (temp->next != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << temp->data;
}

int MList::Length()
{
	int length = 0;
	node* temp = this->head;
	while (temp != nullptr)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

bool MList::isEmpty()
{
	return this->head == nullptr;
}

int MList::ValueAt(int index)
{
	if (index < 0)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	node* temp = this->head;
	for (int i = 0; i < index && temp != nullptr; i++)
	{
		temp = temp->next;
	}
	if (temp == nullptr)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	return temp->data;
}
