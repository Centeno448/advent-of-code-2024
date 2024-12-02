#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <format>

#include "1day.h"

using namespace std;

int main()
{
    ifstream in(INPUT_FILE, ifstream::in);
    string line;

    std::vector<int> left_list;
    std::vector<int> right_list;

    int res = 0, res2 = 0;

    while (getline(in, line))
    {
        const size_t space_index = line.find(' ');

        int left = stoi(line);
        int right = stoi(line.substr(space_index));

        left_list.push_back(left);
        right_list.push_back(right);
    }

    stable_sort(left_list.begin(), left_list.end());
    stable_sort(right_list.begin(), right_list.end());

    for (int i = 0; i < left_list.size(); i++)
    {
        int left = left_list[i];
        res += abs(left - right_list[i]);
        int factor = count_if(right_list.cbegin(), right_list.cend(), [&left](const int &n)
                              { return n == left; });
        res2 += left * factor;
    }

    std::cout << format("day 1-1 res: {}", res) << std::endl;
    std::cout << format("day 1-2 res: {}", res2) << std::endl;
}
