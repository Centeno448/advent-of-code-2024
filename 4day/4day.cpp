#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>

#include "4day.h"

using namespace std;

typedef std::vector<std::vector<char>> CharMatrix;

void print_matrix(const CharMatrix &matrix)
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

void count_vertical_xmas(int &res, const CharMatrix &matrix)
{
    const size_t total_rows = matrix.size(), total_columns = matrix.at(0).size();

    for (size_t row_index = 0; row_index < total_rows; ++row_index)
    {
        for (size_t column_index = 0; column_index < total_columns; ++column_index)
        {
            if (matrix.at(row_index).at(column_index) == 'X')
            {
                if (row_index -)
            }
        }
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
    CharMatrix char_matrix;

    int res = 0, res2 = 0;

    const char test[] = {'M', 'A', 'S'};

    while (getline(in, line))
    {
        std::vector<char> columns;
        std::string forward_copy = line;
        std::string backwards_copy = line;

        while (forward_copy.find("XMAS") != string::npos)
        {
            forward_copy = forward_copy.substr(forward_copy.find("XMAS") + 4);
            ++res;
        }

        while (backwards_copy.find("SAMX") != string::npos)
        {
            backwards_copy = backwards_copy.substr(backwards_copy.find("XMAS") + 4);
            ++res;
        }

        for (const char &c : line)
        {
            columns.push_back(c);
        }

        char_matrix.push_back(columns);
    }

    in.close();

    count_vertical_xmas(res, char_matrix);

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
