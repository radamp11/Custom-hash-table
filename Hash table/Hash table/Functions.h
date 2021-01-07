#pragma once

#include <string>

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
	return 1;
}