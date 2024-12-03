#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <format>

#include "2day.h"

using namespace std;

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

        int current = 0, prev = 0;
        bool ascending;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int element = nums.at(i);

            if (i == 1)
            {
                if (abs(element - prev) > 3)
                {
                    return false;
                }

                if (element > prev)
                {
                    ascending = true;
                }
            }
            else if (i != 0)
            {
                if (element > prev && !ascending)
                {
                    break;
                }
            }

            prev = element;
        }

        std::cout << std::endl;
    }

    std::cout << format("day 1-1 res: {}", res) << std::endl;
    std::cout << format("day 1-2 res: {}", res2) << std::endl;
}
