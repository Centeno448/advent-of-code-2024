#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <vector>
#include <regex>
#include <map>
#include <cmath>

#include "6day.h"

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
    }

    in.close();

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
