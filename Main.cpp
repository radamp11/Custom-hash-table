// Hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
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

    string fileName = "";
    

    HashTable hTable(stoi(argv[1], 0), h_func);
    int choice = -1;
    while (choice != 0)
    {
        cout << "Choose what you want to do:\n1.Insert  2.Erase  3.Print  4.Change the input file\n"
                    "5.Clear the table  0.Exit\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                string s;
                int elems;
                int inserted = 0;
                int ver;
                std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>();
                cout << "Insert elements. Declare the number of elements to insert." << endl;
                cin >> elems;
                cout << "Enter: 1 to read from std input, 2 to read from file" << endl;
                cin >> ver;
                switch (ver)
                {
                    case 1:
                    {
                        while (elems > 0)
                        {   
                            cin >> s;
                            auto start = std::chrono::steady_clock::now();
                            hTable.insert(s);
                            auto end = std::chrono::steady_clock::now();
                            ++inserted;
                            elapsed_seconds += end - start;
                            --elems;
                        }
                        cout << "Done!\n";
                        cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << endl;
                    }
                    break;
                    case 2:
                    {
                        if (fileName == "")
                        {
                            cout << "Enter the name of the input file: ";
                            cin >> fileName;
                        }
                        fstream file;
                        file.open(fileName, ios::in);
                        if (file.is_open())
                        {
                            while (elems > 0)
                            {
                                file >> s;
                                auto start = std::chrono::steady_clock::now();
                                hTable.insert(s);
                                auto end = std::chrono::steady_clock::now();
                                ++inserted;
                                elapsed_seconds += end - start;
                                --elems;
                            }
                            cout << "Done!\n";
                            cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << endl;
                        }
                        else
                            file.clear();
                        file.close();
                        
                    }
                    break;
                    default:
                        cout << "Unknown command." << endl;
                        break;
                }

            }
                break;
            case 2:
            {
                string s;
                int elems;
                int erased = 0;
                int ver;
                std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>();
                cout << "Erase elements. Enter the number of elements to erase: ";
                cin >> elems;
                cout << "Enter: 1 to read from std input, 2 to read from file" << endl;
                cin >> ver;
                switch (ver)
                {
                    case 1:
                    {
                        while (elems > 0)
                        {  
                            cin >> s;
                            auto start = std::chrono::steady_clock::now();
                            hTable.erase(s);
                            auto end = std::chrono::steady_clock::now();
                            ++erased;
                            elapsed_seconds += end - start;
                            --elems;
                        }
                        cout << "Done!\n";
                        cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << endl;
                    }
                    break;
                    case 2:
                    {
                        if (fileName == "")
                        {
                            cout << "Enter the name of the input file: ";
                            cin >> fileName;
                        }
                        fstream file;
                        file.open(fileName, ios::in);
                        if (file.is_open())
                        {
                            while (elems > 0)
                            {
                                file >> s;
                                auto start = std::chrono::steady_clock::now();
                                hTable.erase(s);
                                auto end = std::chrono::steady_clock::now();
                                ++erased;
                                elapsed_seconds += end - start;
                                --elems;
                            }
                            cout << "Done!\n";
                            cout << "elapsed time: " << elapsed_seconds.count() << "s\n" << endl;
                        }
                        else
                            file.clear();
                        file.close();
                        
                    }
                    break;
                    default:
                        cout << "Unknown command." << endl;
                        break;
                }
            }
                break;
            case 3:
                cout << hTable << endl;
                break;
            case 4:
                cout << "Enter the name of the input file: ";
                cin >> fileName;
                cout << fileName;
                break;
            case 5:
                hTable.clear();
                cout << "Done." << endl;
                break;
            case 0:
                cout << "Bye!" << endl;
                break;
            default:
                cout << "Unknown command." << endl;
                break;
        }
    }
}
