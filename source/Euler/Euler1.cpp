#include "Euler1.h"
#include <iostream>

void Euler1::Driver()
{
	std::cout << MultiplesOf3or5(1000) << "\n";
}

int Euler1::MultiplesOf3or5(int limit)
{
	int sum = 0;

	for(int i = 3; i < limit; i += 3)
	{
		sum += i;
	}
	
	for(int i = 5; i < limit; i += 5)
	{
		if (i % 3 != 0)
		{
			sum += i;
		}
	}
	return sum;
}