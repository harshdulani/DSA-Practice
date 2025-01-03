#include "Arrays1.h"
#include <map>

int Arrays1::LargestElement(const std::vector<int>& Arr)
{
	int Max = Arr[0];

	for (int i = 1; i < Arr.size(); ++i)
	{
		if (Arr[i] > Max)
			Max = Arr[i];
	}
	return Max;
}

void Arrays1::SecondLargestElement(const std::vector<int>& Arr, int& OutSecondLargest, int& OutSecondSmallest)
{
	if (Arr.size() > 2)
	{
		OutSecondLargest = INT_MIN;
		OutSecondSmallest = INT_MAX;
	
		int Largest = INT_MIN;
		int Smallest = INT_MAX;

		for (int i = 0; i < Arr.size(); ++i)
		{
			if (Arr[i] > Largest)
			{
				if (Largest != INT_MIN)
					OutSecondLargest = Largest;
			
				Largest = Arr[i];
			}
			else if (Arr[i] > OutSecondLargest && Arr[i] != Largest)
				OutSecondLargest = Arr[i];
		
			if (Arr[i] < Smallest)
			{
				if (Smallest != INT_MAX)
					OutSecondSmallest = Smallest;

				Smallest = Arr[i];
			}
			else if (Arr[i] < OutSecondSmallest && Arr[i] != Smallest)
				OutSecondSmallest = Arr[i];
		}
	}

	if (OutSecondLargest == INT_MIN)
		OutSecondLargest = -1;
	if (OutSecondSmallest == INT_MAX)
		OutSecondSmallest = -1;
}

bool Arrays1::IsArraySorted(const std::vector<int>& Arr)
{
	if (Arr.size() == 1)
		return true;
	
	bool bAsc = Arr[0] < Arr[1];
	int PrevItem = Arr[0];
	
	for (int i = 1; i < Arr.size(); ++i)
	{
		// Item n is greater than item n + 1, order is not asc
		if (PrevItem > Arr[i] && bAsc)
			return false;

		// Item n is smaller than item n + 1, order is not desc
		if (PrevItem < Arr[i] && !bAsc)
			return false;

		PrevItem = Arr[i];
	}
	return true;
}

bool Arrays1::IsArraySorted_Leet(const std::vector<int>& Arr)
{
	//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
	int rots = -1;

	for (size_t i = 0; i < Arr.size() - 1; ++i)
	{
		// check if current element pair is sorted
		if (Arr[i] > Arr[i + 1])
		{
			// if the current pair is not, it may be a rotated array
			// where i + 1 is the actual start, i.e. array is rotated i + 1 times
			if (rots != -1)
			{
				// if a previous pair was also not sorted, array is not sorted
				return false;
			}
                
			rots = i + 1;
			// if it is a rotated array,
			// array {0, ..rots - 1} is sorted 
			// array {rots, ..nums() - 1} is sorted
			// and array {nums() - 1, 0} is sorted
			// check for the last array now, saving unnecessary checks
			if (Arr[Arr.size() - 1] > Arr[0])
				return false;
		}
	}
	return true;
}

int Arrays1::RemoveDuplicates(std::vector<int>& Arr)
{
	//https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/
	int i = 0;
	for (size_t j = 1; j < Arr.size(); ++j)
	{
		if (Arr[i] != Arr[j])
			Arr[++i] = Arr[j];
	}
	return i;
}

void Arrays1::RotateLeft(std::vector<int>& Arr, int k)
{
	while (k--)
	{
		int x = Arr[0];
		for (size_t i = 0; i < Arr.size() - 1; ++i)
			Arr[i] = Arr[i + 1];

		Arr[Arr.size() - 1] = x;
	}
}

void Arrays1::RRotateKTimes(std::vector<int>& Arr, int k)
{
	//https://leetcode.com/problems/rotate-array/
	k %= Arr.size();
	if (k == 0) return;

	std::reverse(Arr.begin(), Arr.end());
	std::reverse(Arr.begin(), Arr.begin() + k);
	std::reverse(Arr.begin() + k, Arr.end());
}

void Arrays1::MoveZeroes(std::vector<int>& nums)
{
	//https://leetcode.com/problems/move-zeroes/
	int j = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0) continue;

		bool bFound = false;
		if (j <= i)
			j = i + 1;

		while (j < nums.size())
		{
			if (nums[j] != 0)
			{
				nums[i] = nums[j];
				nums[j] = 0;
				bFound = true;
				break;
			}
			j++;
		}
		if (!bFound) return;
	}
}

std::vector<int> Arrays1::UnionOfSortedArrays(const std::vector<int>& arr1, const std::vector<int>& arr2)
{
	std::vector<int> result;
	static auto PushIfValidated = [&result](const int& item) -> void
		{
			if (result.empty() || result.back() != item)
				result.push_back(item);
		};
	
	const size_t m = arr1.size();
	const size_t n = arr2.size();

	size_t i = 0;
	size_t j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
		{
			PushIfValidated(arr1[i++]);
		}
		else if (arr1[i] > arr2[j])
		{
			PushIfValidated(arr2[j++]);
		}
		else if (arr1[i] == arr2[j])
		{
			PushIfValidated(arr1[i++]);
			++j;
		}
	}
	while (i < m)
	{
		PushIfValidated(arr1[i++]);
	}
	while (j < n)
	{
		PushIfValidated(arr2[j++]);
	}
	
	return result;
}

int Arrays1::MissingInteger(const std::vector<int>& arr)
{
	//https://leetcode.com/problems/missing-number/

	int N = arr.size();
	unsigned long long Expected = N * (N + 1) * 0.5f;
	unsigned long long Sum = 0;
	for (int i = 0; i < N; ++i)
		Sum += arr[i];

	return Expected - Sum;
}

int Arrays1::FindMaxConsecutiveOnes(const std::vector<int>& arr)
{
	//https://leetcode.com/problems/max-consecutive-ones/
	int max1 = 0;
	int curr = 0;
	for (int num : arr)
	{
		if (num == 1)
		{
			if (++curr > max1)
				max1 = curr;
		}
		else
		{
			curr = 0;
		}
	}
	return max1;
}

int Arrays1::FindSingleNumber(const std::vector<int>& arr)
{
	//https://leetcode.com/problems/single-number/
	long long Sum = 0;
	for (const int& num : arr)
		Sum ^= num;
	return Sum;
}

int Arrays1::LongestSubarrayOfSum_Positives(const std::vector<int>& arr, int k)
{
	//https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399

	int maxLen = 0;

	int left = 0, right = 0;
	long long sum = arr[0];
	int n  = arr.size();

	while (right < n)
	{
		// if sum > k, reduce the subarray from left
		// until sum becomes less or equal to k:
		while (left <= right && sum > k)
		{
			sum -= arr[left++];
		}

		// if sum = k, update the maxLen i.e. answer:
		if (sum == k)
		{
			maxLen = std::max(maxLen, right - left + 1);
		}

		// Move forward thw right pointer:
		if (++right < n)
			sum += arr[right];
	}
    
	return maxLen;
}

int Arrays1::LongestSubarrayOfSum_NegPos(const std::vector<int>& arr, int k)
{
	int n = arr.size(); // size of the array.

	std::map<int, int> preSumMap;
	int sum = 0;
	int maxLen = 0;
	for (int i = 0; i < n; i++)
	{
		//calculate the prefix sum till index i:
		sum += arr[i];

		// if the sum = k, update the maxLen:
		if (sum == k)
		{
			maxLen = std::max(maxLen, i + 1);
		}

		// calculate the sum of remaining part i.e. x-k:
		int rem = sum - k;

		//Calculate the length and update maxLen:
		if (preSumMap.find(rem) != preSumMap.end())
		{
			int len = i - preSumMap[rem];
			maxLen = std::max(maxLen, len);
		}

		//Finally, update the map checking the conditions:
		if (preSumMap.find(sum) == preSumMap.end())
		{
			preSumMap[sum] = i;
		}
	}

	return maxLen;
}
