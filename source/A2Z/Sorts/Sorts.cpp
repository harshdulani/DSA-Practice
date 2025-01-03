#include "Sorts.h"

// select an element and bring the rest of the elements on its left or right - so that it is in its right place in the array, keep doing this to the subarrays
void Sorts::Quick(std::vector<int>& Array, int low, int high)
{
	auto Partition = [](std::vector<int>& Array, int low, int high) -> int
		{
			int pivot = Array[low];
			int i = low;
			int j = high;

			while (i < j)
			{
				while (Array[i] <= pivot && i <= high - 1)
					i++;
				
				while (Array[j] > pivot && j >= low + 1)
					j--;
				
				if (i < j)
					std::swap(Array[i], Array[j]);
			}
			std::swap(Array[low], Array[j]);
			return j;
		};

	if (low >= high)
		 return;

	int pIndex = Partition(Array, low, high);
	Quick(Array, low, pIndex - 1);
	Quick(Array, pIndex + 1, high);
}

// just recursively increase the size of the subset using recursion instead of another loop 
void Sorts::InsertionR(std::vector<int>& Array, int high)
{
	if (high == Array.size())
		return;

	for (int i = high; i > 0; --i)
	{
		if (Array[i] < Array[i - 1])
			std::swap(Array[i], Array[i-1]);
		else
			break;
	}
	InsertionR(Array, high + 1);
}

// just recursively reduce the size of the subset using recursion instead of another loop 
void Sorts::BubbleR(std::vector<int>& Array, int high)
{
	if (high <= 1)
		return;

	for (int j = 1; j < high; ++j)
	{
		if (Array[j - 1] > Array[j])
			std::swap(Array[j - 1], Array[j]);
	}
	BubbleR(Array, high - 1);
}

// Divide array into 2 equal parts till you reach 2 arrays of size 1; sort each subarray (low and high inclusive)
void Sorts::Merge(std::vector<int>& Array, int low, int high)
{
	static auto MergeInternal = [](std::vector<int>& Array, int low, int mid, int high) -> void
		{
			std::vector<int> temp;
			temp.reserve(high - low);
			
			int l = low;
			int r = mid + 1;
			
			while (l <= mid && r <= high)
			{
				if (Array[l] <= Array[r])
					temp.push_back(Array[l++]);
				else
					temp.push_back(Array[r++]);
			}
			while (l <= mid)
			{
				temp.push_back(Array[l++]);
			}
			while (r <= high)
			{
				temp.push_back(Array[r++]);
			}

			for (int i = low; i <= high; ++i)
			{
				Array[i] = temp[i - low];
			}
		};
	if (low == high) return;

	const auto mid = (low + high) / 2;
	Merge(Array, low, mid);
	Merge(Array, mid + 1, high);
	MergeInternal(Array, low, mid, high);
}

// Keep increasing subarray from length 1 to vector length, such that each iteration brings its last element to the right spot by swapping left if larger than previous
void Sorts::Insertion(std::vector<int>& Array)
{
	for (int i = 1; i < Array.size(); ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (Array[j] < Array[j - 1])
				std::swap(Array[j], Array[j - 1]);
			else
				break;
		}
	}
}

// Keep swapping adjacent elements from left to right => low to high over iterations, at the end of iteration i, last i + 1 elements are sorted
void Sorts::Bubble(std::vector<int>& Array)
{
	for (int i = 0; i < Array.size(); ++i)
	{
		if (i == Array.size() - 1)
			return;

		for (int j = 1; j < Array.size() - i; ++j)
		{
			if (Array[j - 1] > Array[j])
				std::swap(Array[j - 1], Array[j]);
		}
	}
}

// Keep "selecting" the low element of a shrinking (from L to R => low to high) subarray and place it at the start of the main array   
void Sorts::Selection(std::vector<int>& Array)
{
	for (int i = 0; i < Array.size(); ++i)
	{
		if (i == Array.size() - 1)
			return;

		int low_idx = i;
		for (int j = i + 1; j < Array.size(); ++j)
		{
			if (Array[j] < Array[low_idx])
			{
				low_idx = j;
			}
		}

		if (low_idx != i)
			std::swap(Array[i], Array[low_idx]);
	}
}
