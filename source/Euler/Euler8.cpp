#include "Euler8.h"

#include <iostream>

std::string Euler8::problemString_ = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";;

void Euler8::Driver()
{
	int nums[1000];
	for (size_t i = 0; i < problemString_.size(); ++i)
	{
		nums[i] = problemString_[i] - '0';
	}
	std::cout << InPlace(5) << " \n";
	std::cout << Hackerrank(nums, 1000, 14) << " \n";
}

uint64_t Euler8::InPlace(int windowSize)
{
	int l = 0;
	int r = 0;
	
	std::string numStr = problemString_;
	//std::string numStr = "2709360626";
	int nums[1000];
	int currWindowSize = 1;
	
	nums[r] = numStr[r] - '0';
	uint64_t prod = nums[r];
	uint64_t maxProd = 0;
	while (r < numStr.size() - 1)
	{
		if (r < numStr.size() - 1)
		{
			nums[r + 1] = numStr[r + 1] - '0';
		}
		if (nums[l] == 0 || nums[r + 1] == 0)
		{
			// move entire window ahead because then this window would contain a "x * 0" condition
			l = ++r;
			currWindowSize = 1;
			nums[r] = numStr[r] - '0';
			prod = nums[r];
			continue;
		}
		if (currWindowSize == windowSize)
		{
			prod /= nums[l++];
		}
		else 
			++currWindowSize;
		prod *= nums[++r];
		

		// only consider max product if you have met window size constraint
		if (prod > maxProd && currWindowSize == windowSize)
		{
			maxProd = prod;
		}
	}
  
	return maxProd;
}

uint64_t Euler8::Hackerrank(int nums[], int n, int windowSize)
{
	int l = 0;
	int r = 0;
	
	uint64_t prod = nums[r];
	uint64_t maxProd = prod;
	while (r < n - 1)
	{
		if (nums[l] == 0 || nums[r + 1] == 0)
		{
			// move entire window ahead because then this window would contain a "x * 0" condition
			l = ++r;
			prod = nums[r];
			continue;
		}
		if ((r - l) >= windowSize - 1)
		{
			prod /= nums[l++];
		}
		prod *= nums[++r];
    
		if (prod > maxProd)
		{
			maxProd = prod;
		}
	}
  
	return maxProd;
}
