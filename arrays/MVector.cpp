#include "MVector.h"
#include <stdexcept>

MVector::MVector() : 
	size(0),
	capacity(16),
	arr(new int[capacity])
{}

MVector::MVector(const MVector& mv) :
	size(mv.Length()),
	capacity(mv.Capacity()),
	arr(new int[capacity])
{
	for (int i = 0; i < this->Length(); i++)
	{
		this->Push(mv.arr[i]);
	}
}

MVector::MVector(int length, int element) :
	size(0),
	capacity(16)
{
	if (length <= 0)
	{
		throw std::invalid_argument("Can't initialize the vector with the given length");
	}
	while (this->capacity < length)
	{
		this->capacity *= 2;
	}
	this->arr = new int[capacity];
	for (int i = 0; i < length; i++)
	{
		this->arr[this->size] = element;
		this->size++;
	}
}

MVector::~MVector()
{
	delete[] this->arr;
}

void MVector::Push(int value)
{
	this->IncreaseSize();
	this->arr[size] = value;
	this->size++;
}

void MVector::PushAt(int value, int index)
{
	if (index < 0 || index > this->size)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	this->IncreaseSize();
	if (index == this->size)
	{
		this->arr[size] = value;
		this->size++;
		return;
	}
	for (int i = this->size; i > index; i--)
	{
		this->arr[i] = this->arr[i - 1];
	}
	this->arr[index] = value;
	this->size++;
}

int MVector::Pop()
{
	if (this->size <= 0)
	{
		throw std::invalid_argument("Vector is empty");
	}
	this->DecreaseSize();
	this->size--;
	return this->arr[this->size];
}

int MVector::PopAt(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	if (index == this->size - 1)
	{
		return this->Pop();
	}
	this->DecreaseSize();
	int val = this->arr[index];
	for (int i = index; i < this->size - 1; i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	this->size--;
	return val;
}

int MVector::ValueAt(int index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	return this->arr[index];
}

int MVector::IndexAt(int value)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

bool MVector::isEmpty()
{
	return size == 0;
}

int MVector::Length() const
{
	return this->size;
}

int MVector::Capacity() const 
{
	return this->capacity;
}

bool MVector::operator==(const MVector& mv)
{
	if (this->Length() != mv.Length())
	{
		return false;
	}
	for (int i = 0; i < this->Length(); i++)
	{
		if (arr[i] != mv.arr[i])
		{
			return false;
		}
	}
	return true;
	 
}

void MVector::IncreaseSize()
{
	if (this->Length() == this->capacity)
	{
		this->capacity *= 2;
		int* newArray = new int[capacity];
		for (int i = 0; i < this->Length(); i++)
		{
			newArray[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = newArray;
	}
}

void MVector::DecreaseSize()
{
	if (this->size <= this->capacity / 4)
	{
		this->capacity /= 2;
		int* newArray = new int[capacity];
		for (int i = 0; i < this->Length(); i++)
		{
			newArray[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = newArray;
	}

}

int MVector::operator[](int index)
{
	if (index >= this->Length() || index < 0)
	{
		throw std::invalid_argument("Index out of bounds");
	}
	return this->arr[index];
}

void MVector::PrintAddresses()
{
	for (int i = 0; i < this->Length(); i++)
	{
		std::cout << this->arr + i << " ";
	}
}

void MVector::PrintValues()
{
	for (int i = 0; i < this->Length(); i++)
	{
		std::cout << *(this->arr + i) << " ";
	}
}

std::ostream& operator<<(std::ostream& out, const MVector& mv)
{
	for (int i = 0; i < mv.Length(); i++)
	{
		out << mv.arr[i] << " ";
	}
	return out;
}
