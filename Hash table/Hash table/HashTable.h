#pragma once

#include <iostream>
#include <string>

class HashTable
{
	std::string** table;
	size_t size;
	int (*hashFunc)(std::string, size_t);

public:
	HashTable(int k, int (*func)(std::string, size_t));
	int insert(const std::string&);
	std::string operator[](int);
	size_t operator[](const std::string&);
	friend std::ostream& operator<<(std::ostream& os, const HashTable&);
	~HashTable();
};