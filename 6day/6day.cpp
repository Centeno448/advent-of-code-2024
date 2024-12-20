#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>

#include "6day.h"

using namespace std;

typedef vector<vector<char>> GuardMap;
typedef pair<int, int> Position;

enum MovementDirection
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

void print_map(const GuardMap &map)
{
    for (const auto &row : map)
    {
        for (const auto &col : row)

        {
            std::cout << col;
        }
        std::cout << std::endl;
    }
}

MovementDirection update_movement_direction(const MovementDirection &current)
{
    switch (current)
    {
    case MovementDirection::UP:
        return MovementDirection::RIGHT;

    case MovementDirection::RIGHT:
        return MovementDirection::DOWN;

    case MovementDirection::DOWN:
        return MovementDirection::LEFT;

    case MovementDirection::LEFT:
        return MovementDirection::UP;

    default:
        return MovementDirection::UP;
    }
}

Position get_next_position(const Position &current, const MovementDirection &direction)
{
    switch (direction)
    {
    case MovementDirection::UP:
        return Position(current.first - 1, current.second);

    case MovementDirection::RIGHT:
        return Position(current.first, current.second + 1);

    case MovementDirection::DOWN:
        return Position(current.first + 1, current.second);

    case MovementDirection::LEFT:
        return Position(current.first, current.second - 1);

    default:
        return Position(-1, -1);
    }
}

void count_unique_steps(GuardMap &map, Position starting_pos, int &res)
{
    MovementDirection mov_direction = MovementDirection::UP; // start moving upwards
    Position pos = starting_pos;

    while (true)
    {
        char current_char = map.at(pos.first).at(pos.second);

        if (current_char != 'X')
        {
            map.at(pos.first).at(pos.second) = 'X';
            res += 1;
        }

        Position next = get_next_position(pos, mov_direction);

        if (next.first > map.size() - 1 || next.first < 0)
        {
            break;
        }

        if (next.second > map.at(0).size() - 1 || next.second < 0)
        {
            break;
        }

        char next_char = map.at(next.first).at(next.second);

        if (next_char == '#')
        {
            mov_direction = update_movement_direction(mov_direction);
        }

        pos = get_next_position(pos, mov_direction);
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
        cout << format("Invalid argument {}", argv[1]) << endl;
        return -1;
    }

    string line;
    GuardMap guard_map;

    int res = 0, res2 = 0;
    Position starting_pos;
    int row = 0;

    while (getline(in, line))
    {
        std::vector<char> columns;
        int col = 0;

        for (const char &c : line)
        {
            if (c == '^')
            {
                starting_pos.first = row;
                starting_pos.second = col;
            }

            columns.push_back(c);
            ++col;
        }

        guard_map.push_back(columns);
        ++row;
    }

    in.close();

    count_unique_steps(guard_map, starting_pos, res);

    cout << format("day 6-1 res: {}", res) << endl;
    cout << format("day 6-2 res: {}", res2) << endl;
}
