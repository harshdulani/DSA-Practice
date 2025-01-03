#pragma once
#include <vector>

class GraphTraversal
{
public:
	static void Driver();

	static std::vector<int> GetDfs(int v, int start, const std::vector<std::vector<int>>& adj);
	static std::vector<int> GetBfs(int v, int start, const std::vector<std::vector<int>>& adj);
};
