#pragma once
#include <string>

class Euler8
{
public:
	static void Driver();
	
private:
	static uint64_t InPlace(int windowSize);
	static uint64_t Hackerrank(int nums[], int n, int windowSize);

	static std::string problemString_;
};
