#include <iostream>
#include <vector>

#include "A2Z/Arrays/Arrays2.h"

void PrintArray(const std::vector<int>& nums)
{
	for (const int n : nums)
	{
		std::cout << n << ", ";
	}
}

int main()
{
	std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	std::cout << Arrays2::KadaneMaxSubarray(nums);
	
	return 0;
}