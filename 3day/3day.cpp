#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <regex>

#include "3day.h"

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

    std::regex mul_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    while (getline(in, line))
    {
        smatch mul_match;
        while (regex_search(line, mul_match, mul_regex))
        {
            int left = stoi(mul_match[1]);
            int right = stoi(mul_match[2]);
            res += left * right;
            line = mul_match.suffix();
        }
    }

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
