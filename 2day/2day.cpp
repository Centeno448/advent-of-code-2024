#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <format>

#include "2day.h"

using namespace std;

bool is_safe(const std::vector<int> &nums)
{
    int prev = nums.at(0);
    bool ascending = false;

    for (size_t i = 1; i < nums.size(); i++)
    {
        int element = nums.at(i);

        if (i == 1)
        {
            if (abs(element - prev) > 3)
            {
                return false;
            }

            if (element == prev)
            {
                return false;
            }

            if (element > prev)
            {
                ascending = true;
            }
        }
        else
        {
            if (abs(element - prev) > 3)
            {
                return false;
            }

            if (element == prev)
            {
                return false;
            }

            if (element > prev && !ascending || element < prev && ascending)
            {
                return false;
            }
        }

        prev = element;
    }

    return true;
}

bool is_safe_dampener(const std::vector<int> &nums)
{
    if (is_safe(nums))
    {
        return true;
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        std::vector<int> copy(nums.begin(), nums.end());
        copy.erase(copy.begin() + i);
        if (is_safe(copy))
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    ifstream in;

    if (argc < 2)
    {
        in.open(INPUT_FILE);
    }
    else if (strcmp(argv[1], "-t") == 0)
    {
        in.open(TEST_INPUT_FILE);
    }
    else
    {
        cout << format("Invalid argument {}", argv[1]) << std::endl;
        return -1;
    }

    string line;

    int res = 0, res2 = 0;

    while (getline(in, line))
    {
        std::vector<int> nums;
        int num = 0;
        string num_str;

        size_t last = 0, next = 0;

        while ((next = line.find(' ', last)) != string::npos)
        {

            string num_str = line.substr(last, next - last);
            num = stoi(num_str);
            nums.push_back(num);

            last = next + 1;
        }

        num_str = line.substr(last);
        num = stoi(num_str);
        nums.push_back(num);

        if (is_safe(nums))
        {
            ++res;
        }

        if (is_safe_dampener(nums))
        {
            ++res2;
        }
    }

    in.close();

    std::cout << format("day 2-1 res: {}", res) << std::endl;
    std::cout << format("day 2-2 res: {}", res2) << std::endl;
}
