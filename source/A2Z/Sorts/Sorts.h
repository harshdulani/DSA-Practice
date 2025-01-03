#pragma once
#include <vector>

class Sorts
{
public:
	static void Quick(std::vector<int>& Array, int min, int max);
	static void InsertionR(std::vector<int>& Array, int max);
	static void BubbleR(std::vector<int>& Array, int max);
	static void Merge(std::vector<int>& Array, int min, int max);
	static void Insertion(std::vector<int>& Array);
	static void Bubble(std::vector<int>& Array);
	static void Selection(std::vector<int>& Array);
};
