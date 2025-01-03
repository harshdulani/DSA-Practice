#pragma once
#include <vector>

class Arrays1
{
public:
	static int LargestElement(const std::vector<int>& Arr);
	static void SecondLargestElement(const std::vector<int>& Arr, int& OutSecondLargest, int& OutSecondSmallest);
	static bool IsArraySorted(const std::vector<int>& Arr);
	static bool IsArraySorted_Leet(const std::vector<int>& Arr);
	static int RemoveDuplicates(std::vector<int>& Arr);
	static void RotateLeft(std::vector<int>& Arr, int k);
	static void RRotateKTimes(std::vector<int>& Arr, int k);
	static void MoveZeroes(std::vector<int>& nums);
	static std::vector<int> UnionOfSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2);
	static int MissingInteger(const std::vector<int>& arr);
	static int FindMaxConsecutiveOnes(const std::vector<int>& arr);
	static int FindSingleNumber(const std::vector<int>& arr);
	// needs revision
	static int LongestSubarrayOfSum_Positives(const std::vector<int>& arr, int k);
	// needs revision
	static int LongestSubarrayOfSum_NegPos(const std::vector<int>& arr, int k);
};
