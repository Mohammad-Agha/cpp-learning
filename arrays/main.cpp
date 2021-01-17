#include <iostream>
#include "MVector.h"

int main()
{
	MVector mv;
	for (int i = 0; i < 10; i++)
	{
		mv.Push(i);
	}
	std::cout << mv.IndexAt(100);
	return 1;
}