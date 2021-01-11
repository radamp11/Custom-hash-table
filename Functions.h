#pragma once

#include <string>
#include <cmath>

int hashFunction_1(std::string s, size_t size)
{
	unsigned hash = 5381;
	for (char c : s)
	{
		hash = (hash << 5) + hash + c;
	}
	return hash % size;
}

int hashFunction_2(std::string s, size_t size)
{
	unsigned p = 23;
	unsigned suma = 0;
	for (size_t i = 0; i < s.length(); ++i)
	{
		suma += pow(p, i) * s[i];
	}
	return suma % size;
}

int hashFunction_3(std::string s, size_t size)
{
	return 100 % size;
}

