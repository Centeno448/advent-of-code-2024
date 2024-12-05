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
    std::regex mul_regex2("mul\\((\\d{1,3}),(\\d{1,3})\\)|(do\\(\\))|(don't\\(\\))");

    while (getline(in, line))
    {
        std::string copy = line;
        smatch mul_match;
        while (regex_search(copy, mul_match, mul_regex))
        {
            int left = stoi(mul_match[1]);
            int right = stoi(mul_match[2]);
            res += left * right;
            copy = mul_match.suffix();
        }

        std::string copy2 = line;
        smatch mul_match2;
        bool process = true;
        while (regex_search(copy2, mul_match2, mul_regex2))
        {
            if (mul_match2[0].str() == "do()")
            {
                process = true;
            }
            else if (mul_match2[0].str() == "don't()")
            {
                process = false;
            }
            else
            {
                if (process)
                {
                    int left = stoi(mul_match2[1]);
                    int right = stoi(mul_match2[2]);
                    res2 += left * right;
                }
            }

            copy2 = mul_match2.suffix();
        }
    }

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
