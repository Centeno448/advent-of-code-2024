#include <iostream>
#include <fstream>
#include <sstream>
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

void count_horizontally(int &res, const CharMatrix &matrix, const int row_index, const int column_index)
{
    bool build_left = true, build_right = true;

    if (column_index - 3 < 0)
    {
        build_left = false;
    }

    if (column_index + 3 > matrix.at(0).size() - 1)
    {
        build_right = false;
    }

    stringstream left, right;

    for (int i = 0; i < 3; ++i)
    {
        if (build_left)
        {
            left << matrix.at(row_index).at(column_index - i - 1);
        }

        if (build_right)
        {
            right << matrix.at(row_index).at(column_index + i + 1);
        }
    }

    if (left.str() == "MAS")
    {
        ++res;
    }

    if (right.str() == "MAS")
    {
        ++res;
    }
}

void count_vertically(int &res, const CharMatrix &matrix, const int row_index, const int column_index)
{
    bool build_top = true, build_bottom = true;

    if (row_index - 3 < 0)
    {
        build_top = false;
    }

    if (row_index + 3 > matrix.size() - 1)
    {
        build_bottom = false;
    }

    stringstream top, bottom;

    for (int i = 0; i < 3; ++i)
    {
        if (build_top)
        {
            top << matrix.at(row_index - i - 1).at(column_index);
        }

        if (build_bottom)
        {
            bottom << matrix.at(row_index + i + 1).at(column_index);
        }
    }

    if (top.str() == "MAS")
    {
        ++res;
    }

    if (bottom.str() == "MAS")
    {
        ++res;
    }
}

void count_diagonally(int &res, const CharMatrix &matrix, const int row_index, const int column_index)
{
    bool build_top_left = true, build_top_right = true, build_bottom_left = true, build_bottom_right = true;

    if (row_index - 3 < 0)
    {
        build_top_left = false;
        build_top_right = false;
    }

    if (column_index - 3 < 0)
    {
        build_top_left = false;
        build_bottom_left = false;
    }

    if (column_index + 3 > matrix.at(0).size() - 1)
    {
        build_top_right = false;
        build_bottom_right = false;
    }

    if (row_index + 3 > matrix.size() - 1)
    {
        build_bottom_left = false;
        build_bottom_right = false;
    }

    stringstream top_left, top_right, bottom_left, bottom_right;

    for (int i = 0; i < 3; ++i)
    {
        if (build_top_left)
        {
            top_left << matrix.at(row_index - i - 1).at(column_index - i - 1);
        }

        if (build_top_right)
        {
            top_right << matrix.at(row_index - i - 1).at(column_index + i + 1);
        }

        if (build_bottom_left)
        {
            bottom_left << matrix.at(row_index + i + 1).at(column_index - i - 1);
        }

        if (build_bottom_right)
        {
            bottom_right << matrix.at(row_index + i + 1).at(column_index + i + 1);
        }
    }

    if (top_left.str() == "MAS")
    {
        ++res;
    }

    if (top_right.str() == "MAS")
    {
        ++res;
    }

    if (bottom_left.str() == "MAS")
    {
        ++res;
    }

    if (bottom_right.str() == "MAS")
    {
        ++res;
    }
}

void count_xmas(int &res, const CharMatrix &matrix)
{
    const int total_rows = static_cast<int>(matrix.size()), total_columns = static_cast<int>(matrix.at(0).size());

    for (int row_index = 0; row_index < total_rows; ++row_index)
    {
        for (int column_index = 0; column_index < total_columns; ++column_index)
        {
            if (matrix.at(row_index).at(column_index) == 'X')
            {
                count_horizontally(res, matrix, row_index, column_index);
                count_vertically(res, matrix, row_index, column_index);
                count_diagonally(res, matrix, row_index, column_index);
            }
        }
    }
}

void count_x_mases(int &res, const CharMatrix &matrix)
{
    const int total_rows = static_cast<int>(matrix.size()), total_columns = static_cast<int>(matrix.at(0).size());

    for (int row_index = 0; row_index < total_rows; ++row_index)
    {
        for (int column_index = 0; column_index < total_columns; ++column_index)
        {
            if (matrix.at(row_index).at(column_index) == 'A')
            {

                if (row_index - 1 < 0)
                {
                    continue;
                }

                if (column_index - 1 < 0)
                {
                    continue;
                }

                if (column_index + 1 > matrix.at(0).size() - 1)
                {
                    continue;
                }

                if (row_index + 1 > matrix.size() - 1)
                {
                    continue;
                }

                stringstream top_left, top_right;

                top_left << matrix.at(row_index - 1).at(column_index - 1) << matrix.at(row_index).at(column_index) << matrix.at(row_index + 1).at(column_index + 1);

                top_right << matrix.at(row_index - 1).at(column_index + 1) << matrix.at(row_index).at(column_index) << matrix.at(row_index + 1).at(column_index - 1);

                if ((top_left.str() == "MAS" || top_left.str() == "SAM") && (top_right.str() == "MAS" || top_right.str() == "SAM"))
                {
                    ++res;
                }
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

    count_xmas(res, char_matrix);
    count_x_mases(res2, char_matrix);

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
