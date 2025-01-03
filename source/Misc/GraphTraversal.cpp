#include "GraphTraversal.h"
#include <iostream>
#include <queue>
#include <stack>

void GraphTraversal::Driver()
{
	// problem
	std::vector<std::vector<int>> adj =
		{{1}, {0, 2, 3, 4}, {1, 5, 6}, {1, 7}, {1, 10}, {2}, {2}, {3, 8, 9}, {7}, {7}, {4}};
	int v = 10;
	int start = 2;

	// BFS
	std::cout << "\nBFS: ";
	for (auto it : GetBfs(v, start, adj))
	{
		std::cout << it << ",";
	}
	std::cout << "\nDFS: ";
	//DFS
	for (auto it : GetDfs(v, start, adj))
	{
		std::cout << it << ",";
	}
}

std::vector<int> GraphTraversal::GetDfs(int v, int start, const std::vector<std::vector<int>>& adj)
{
	std::stack<int> working;
	std::vector<bool> visited;
	std::vector<int> result;

	visited.resize(v + 1, false);
	working.push(start);
	visited[start] = true;

	while (!working.empty())
	{
		int node = working.top();
		working.pop();

		result.push_back(node);
		for (auto it : adj[node])
		{
			if (!visited[it])
			{
				working.push(it);
				visited[it] = true;
			}
		}
	}
	return result;
}

std::vector<int> GraphTraversal::GetBfs(int v, int start, const std::vector<std::vector<int>>& adj)
{
	std::queue<int> working;
	std::vector<int> bfs;

	std::vector<bool> visited;
	visited.resize(v + 1);
	visited[start] = true;
	working.push(start);

	while (!working.empty())
	{
		int node = working.front();
		//std::cout << node << ",";
		working.pop();
		bfs.push_back(node);
		for (const int neighbor : adj[node])
		{
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				working.push(neighbor);
			}
		}
	}
	return bfs;
}
