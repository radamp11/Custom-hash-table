// Hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "HashTable.h"
#include "Functions.h"

using namespace std;

int main()
{
    HashTable hTable(100000, hashFunction_3);
    string s;
    /*for (int i = 0; i < 20; ++i)
    {
        cin >> s;
        hTable.insert(s);
    }*/
    auto start = std::chrono::steady_clock::now();
    while (cin >> s)
    {
        hTable.insert(s);
    }
    for (int i = 0; i < 50000; ++i)
    {
        hTable.erase("^");
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
