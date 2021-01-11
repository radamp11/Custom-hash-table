// Hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "HashTable.h"
#include "Functions.h"

using namespace std;

int main(int argc, char* argv[])
{
    int (*h_func)(string, size_t);
    switch (stoi(argv[2], 0))
    {
        case 1:
            h_func = &hashFunction_1;
            break;
        case 2:
            h_func = &hashFunction_2;
            break;
        case 3:
            h_func = &hashFunction_3;
            break;
        default:
            exit(1);
    }
    HashTable hTable(stoi(argv[1], 0), h_func);
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
    for (int i = 0; i < 5; ++i)
    {
        hTable.erase("^");
    }
    cout << hTable;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
