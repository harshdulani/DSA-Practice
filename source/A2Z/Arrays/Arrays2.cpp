#include "Arrays2.h"

#include <cmath>

void Arrays2::Sort012(std::vector<int>& nums)
{
	// https://leetcode.com/problems/sort-colors/
	int lowMax = -1;
	int highMin = nums.size();

	for (int i = 0; i < highMin; ++i)
	{
		switch (nums[i])
		{
			// optimise by removing unnecessary swaps
			// for eg, if i == lowMax + 1 or i == highMin - 1
				// we dont need to swap because we're swapping w ourself
			case 0:
				//send to left of array
				if (i > lowMax++)
					std::swap(nums[i], nums[lowMax]);
				break;
			case 1:
				// do nothing, it needs to be in the center of the array
				break;
			case 2:
				// send to right of array
				if (i < highMin--)
					std::swap(nums[i--], nums[highMin]);
				break;
		}
	}
}

int Arrays2::MajorityElement(const std::vector<int>& nums)
{
	//https://www.naukri.com/code360/problems/majority-element_6783241
	// use if problem statement guarantees there is a majority element
	int el = nums[0];
	size_t count = 1;

	// get estimated majority element
	for (size_t i = 1; i < nums.size(); ++i)
	{
		count = count + (el == nums[i] ? 1 : -1);
		if (count == 0)
		{
			el = nums[i];
			count = 1;
		}
	}

	return el;
}

int Arrays2::MajorityElement_Verify(const std::vector<int>& nums)
{
	// if problem statement says there may or may not be a majority element

	// Moore's Voting Algorithm
	int el = nums[0];
	size_t count = 1;
	const size_t minCount = std::ceil(nums.size() * 0.5f);

	auto IsGoodCount = [&minCount](const size_t& count) -> bool
		{
			return  count > minCount;
		};
	
	// get estimated majority element
	for (size_t i = 1; i < nums.size(); ++i)
	{
		count = count + (el == nums[i] ? 1 : -1);
		if (count == 0)
		{
			el = nums[i];
			count = 1;
		}
	}
	if (IsGoodCount(count))
		return el;

	count = 0;
	for (const int num : nums)
	{
		if (num == el)
			count++;
		if (IsGoodCount(count))
			break;
	}
	return el;
}

int Arrays2::KadaneMaxSubarray(const std::vector<int>& nums)
{
	// https://leetcode.com/problems/maximum-subarray/
	int maxSum = nums[0];
	int sum = 0;
	for (int num : nums)
	{
		if (sum < 0)
			sum = 0;
		sum += num;
		if (sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}

int Arrays2::KadaneMaxSubarray(const std::vector<int>& nums, int& start, int& end)
{
	int maxSum = nums[0];
	start = end = 0;
	int sum = 0;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (sum < 0)
		{
			sum = 0;
			end = start = i;
		}
		sum += nums[i];
		if (sum > maxSum)
		{
			maxSum = sum;
			end = i;
		}
	}
	return maxSum;
}

int Arrays2::StockBuySell(const std::vector<int>& nums)
{
	//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
	int lo = nums[0];
	int hi = lo;
	int maxProfit = 0;
	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (nums[i] > hi)
		{
			hi = nums[i];
			maxProfit = std::max(maxProfit, hi - lo);
		}
		else if (nums[i] < lo)
		{
			lo = hi = nums[i];
		}
	}
	
	return maxProfit;
}

std::vector<int> Arrays2::RearrangeAlternateSigns(const std::vector<int>& nums)
{
	// https://www.naukri.com/code360/problems/alternate-numbers_6783445
	std::vector<int> res (nums.size(), 0);

	int posIdx = 0;
	int negIdx = 1;
	
	for (const int num : nums)
	{
		if (num >= 0)
		{
			res[posIdx] = num;
			posIdx += 2;
		}
		else
		{
			res[negIdx] = num;
			negIdx += 2;
		}
	}
	
	return res;
}

void Arrays2::NextPermutation(const std::vector<int>& nums)
{
	
}