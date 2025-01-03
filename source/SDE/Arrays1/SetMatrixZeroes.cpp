#include "SetMatrixZeroes.h"

#include <vector>


void SetMatrixZeroes::SetZeroes(std::vector<std::vector<int>>& matrix)
{
	const size_t n = matrix.size();		// cols
	const size_t m = matrix[0].size();	// rows
	bool flag1 = false, flag2 = false;
	for (size_t i = 0; i < n; i++)
	{
		if (matrix[i][0] == 0)
		{
			flag1 = true;
		}
	}
	for (size_t j = 0; j < m; j++)
	{
		if (matrix[0][j] == 0)
		{
			flag2 = true;
		}
	}
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 1; j < m; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = matrix[0][j] = 0;
			}
		}
	}
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 1; j < m; j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}
	if (flag1 == true)
	{
		for (size_t i = 0; i < n; i++)
		{
			matrix[i][0] = 0;
		}
	}
	if (flag2 == true)
	{
		for (size_t j = 0; j < m; j++)
		{
			matrix[0][j] = 0;
		}
	}
}
