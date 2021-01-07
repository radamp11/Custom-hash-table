#include "HashTable.h"

using namespace std;

HashTable::HashTable(int k, int (*func)(string, size_t))
{
	this->size = k;
	this->table = new string* [k]();
	this->hashFunc = func;
}

int HashTable::insert(const string& s)
{
	int idx = (*hashFunc)(s, size);
	if (table[idx] == nullptr)
		table[idx] = new string(s);
	else
	{
		for (int i = 0; i < size; ++i)
		{
			if (idx + i == size)
				idx = -i;
			if (table[idx + i] == nullptr)
			{
				table[idx + i] = new string(s);
				return idx + i;
			}
		}
	}
	return -1;
}

string HashTable::operator[](int i)
{
	return *table[i];
}

size_t HashTable::operator[](const string& s)
{
	return (*hashFunc)(s, size);
}

ostream& operator<<(ostream& os, const HashTable& htable)
{
	for (int i = 0; i < htable.size; ++i)
	{
		os << i << ". " << htable.table[i] << endl;
	}
	return os;
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; ++i)
		if (table[i] != nullptr)
			delete table[i];
	delete[] table;
}