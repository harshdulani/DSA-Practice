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
	std::vector<int> nums = {1, 2, -3, -1, -2, 3};

	PrintArray(Arrays2::RearrangeAlternateSigns(nums));
	return 0;
}