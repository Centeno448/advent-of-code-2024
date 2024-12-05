#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>

#include "4day.h"

using namespace std;

void print_matrix(const std::vector<std::vector<char>> &matrix)
{
    for (const auto columns : matrix)
    {
        for (const char c : columns)
        {
            std::cout << format("{} ", c);
        }
        std::cout << std::endl;
    }
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
    std::vector<std::vector<char>> char_matrix;

    int res = 0, res2 = 0;

    while (getline(in, line))
    {
        std::vector<char> columns;

        for (const char &c : line)
        {
            columns.push_back(c);
        }

        char_matrix.push_back(columns);
    }

    in.close();

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
