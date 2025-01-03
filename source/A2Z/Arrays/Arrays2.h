#pragma once
#include <vector>

class Arrays2
{
public:
	static void Sort012(std::vector<int>& nums);
	static int MajorityElement(const std::vector<int>& nums);
	static int MajorityElement_Verify(const std::vector<int>& nums);
	static int KadaneMaxSubarray(const std::vector<int>& nums);
	static int KadaneMaxSubarray(const std::vector<int>& nums, int& start, int& end);
};
