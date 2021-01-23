#include <iostream>
#include "MList.h"

int main()
{
	MList list;
	for (int i = 1; i <= 5; i++)
	{
		list.PushEnd(i * 10);
	}
	int k = list.ValueAtBack(0);
	std::cout << k;
}
