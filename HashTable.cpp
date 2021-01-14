#include "HashTable.h"

using namespace std;

HashTable::HashTable(int k, int (*func)(string, size_t))
{
	if (k <= 0)
		throw invalid_argument("Size of the table must be greater than 0.");
	this->size = k;
	this->table = new TField [k];
	this->hashFunc = func;
}

int HashTable::insert(const string& s)
{
	if (!isFull)
	{
		int idx = (*hashFunc)(s, size);
		for (int i = 0; i < size; ++i)
		{
			if (idx + i == size)
				idx = -i;
			if (table[idx + i].isEmpty)
			{
				table[idx + i].str = new string(s);
				table[idx + i].isEmpty = false;
				if (++elems == size)
					isFull = true;
				return idx + i;
			}
		}
	}
	return -1;
}

int HashTable::erase(const string& s)
{
	if (elems > 0)
	{
		int idx = (*hashFunc)(s, size);
		for (int i = 0; i < size; ++i)
		{
			if (idx + i == size)
				idx = -i;
			if (!table[idx + i].isEmpty && table[idx + i].str->compare(s) == 0)
			{
				delete table[idx + i].str;
				table[idx + i].isEmpty = true;
				--elems;
				if (isFull)
					isFull = false;
				return 1;
			}
		}
	}
	return -1;
}

void HashTable::clear()
{
	for (int i = 0; i < size; ++i)
		if (!table[i].isEmpty)
		{
			delete table[i].str;
			table[i].isEmpty = true;
		}
}

string HashTable::operator[](int i)
{
	return *table[i].str;
}

size_t HashTable::operator[](const string& s)
{
	return (*hashFunc)(s, size);
}

ostream& operator<<(ostream& os, const HashTable& htable)
{
	for (int i = 0; i < htable.size; ++i)
	{
		os << i << ". ";
		if (!htable.table[i].isEmpty)
			os << *htable.table[i].str;
		os << endl;
	}
	return os;
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; ++i)
		if (!table[i].isEmpty)
			delete table[i].str;
	delete[] table;
}