#include "Euler9.h"

#include <iostream>

void Euler9::Driver()
{
	// find a*b*c such that a < b < c, a*a + b*b = c*c, and a + b + c = 1000
	std::cout << Soln();
	//std::cout << Brute();
}

int Euler9::Brute()
{
	for (int a = 1; a < 1000; ++a)
	{
		for (int b = a + 1; b < 1000; ++b)
		{
			for (int c = b + 1; c < 1000; ++c)
			{
				if (a + b + c == 1000 && a * a + b * b == c * c)
					return a * b * c;
			}
		}
	}
	return -1;
}

int Euler9::Soln()
{
	for (int a = 1; a < 1000; ++a)
	{
		for (int b = a; (500 - a / 2) < b; ++b)
		{
			int c = 1000 - a - b;
			if (a * a + b * b == c * c)
				return a * b * c;
		}
	}

	return -1;
}
