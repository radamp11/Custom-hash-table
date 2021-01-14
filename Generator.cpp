// Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Generator.h"

using namespace std;


int main(int argc, char* argv[])
{

    unordered_map<char, pair<unordered_map<char, int>, int>> num_of_occur;

    fstream input;
    input.open("text.txt", ios::in);
    if (input.is_open())
    {
        char curr_char, prev_char;
        if (input.read(&curr_char, 1))
        {
            num_of_occur[EOW].first[curr_char]++;
            num_of_occur[EOW].second++;
            prev_char = curr_char;
        }
        while (input.read(&curr_char, 1))
        {
            if ((curr_char < 'A') || (curr_char > 'Z' && curr_char < 'a') || (curr_char > 'z'))
                curr_char = EOW;
            num_of_occur[prev_char].first[curr_char]++;
            num_of_occur[prev_char].second++;
            prev_char = curr_char;
        }
    }
    else
    {
        cerr << "Cannot open the file.";
        return 1;
    }
    input.close();

    unordered_map<char, unordered_map<char, Range>> probability;

    for (auto it = num_of_occur.begin(); it != num_of_occur.end(); ++it)
    {
        auto it2 = it->second.first.begin();
        auto it3 = it2;
        probability[it->first][it2->first].begin = 0;
        probability[it->first][it2->first].end = probability[it->first][it2->first].begin + it2->second;
        ++it2;
        for (it2; it2 != it->second.first.end(); ++it2)
        {
            probability[it->first][it2->first].begin = probability[it->first][it3->first].end;
            probability[it->first][it2->first].end = probability[it->first][it2->first].begin + it2->second;
            ++it3;
        }
    }


    random_device rd;
    mt19937 gen(rd());

    string arg = argv[1];
    const int N = stoi(arg, 0);
    int i = 0;
    while (i < N)
    {
        
        char curr_char, next_char;
        string s = "";
        curr_char = EOW;
        do
        {
            uniform_real_distribution<> dis(0.0, num_of_occur[curr_char].second);
            double rand = dis(gen);
            for (auto it = probability[curr_char].begin(); it != probability[curr_char].end(); ++it)
            {
                if (rand >= it->second.begin && rand < it->second.end)
                {
                    if (it->first != EOW)
                        s += it->first;
                    curr_char = it->first;
                    break;
                }
            }
        } while (curr_char != EOW);
        if (!s.compare(""))
            continue;
        cout << s << endl;
        ++i;
    }
}