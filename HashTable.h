// Authors: Rafał Surdej, Adam Stec -- 01.2021

#pragma once

#include <iostream>
#include <string>
#include <exception>

class HashTable
{
	struct TField
	{
		bool isEmpty = true;
		std::string* str;
	};

	TField* table;
	size_t size;
	size_t elems = 0;
	bool isFull = false;
	int (*hashFunc)(std::string, size_t);

public:
	HashTable(int k, int (*func)(std::string, size_t));
	int insert(const std::string&);
	int erase(const std::string&);
	void clear();
	friend std::ostream& operator<<(std::ostream& os, const HashTable&);
	~HashTable();
};