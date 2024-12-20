#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <vector>
#include <regex>
#include <map>
#include <cmath>

#include "5day.h"

using namespace std;

struct Instruction
{
    Instruction(int b, int a) : before(b), after(a) {}
    int before;
    int after;
};

typedef std::map<string, Instruction> InstructionMap;

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

    regex instruction_regex("(\\d+)\\|(\\d+)");

    bool parsing_instructions = true;

    InstructionMap instructions;

    while (getline(in, line))
    {

        if (line == "")
        {
            parsing_instructions = false;
            continue;
        }

        if (parsing_instructions)
        {
            smatch instruction_match;
            regex_search(line, instruction_match, instruction_regex);

            int before = stoi(instruction_match[1]);
            int after = stoi(instruction_match[2]);

            Instruction instruction(before, after);

            instructions.insert({instruction_match[0], instruction});
        }
        else
        {
            std::vector<int> updates;

            while (line.find(',') != string::npos)
            {
                size_t found = line.find(',');
                int page_num = stoi(line.substr(0, found));
                updates.push_back(page_num);
                line = line.substr(found + 1);
            }

            int page_num = stoi(line);
            updates.push_back(page_num);

            auto current = updates.begin();
            bool valid = true;

            while (current != updates.end())
            {
                auto next = current + 1;
                while (next != updates.end())
                {
                    if (instructions.find(vformat("{}|{}", make_format_args(*current, *next))) != instructions.end())
                    {
                        auto res = instructions.find(vformat("{}|{}", make_format_args(*current, *next)));
                        if (*current == res->second.after)
                        {
                            valid = false;
                            int temp = *next;
                            *next = *current;
                            *current = temp;
                        }
                    }
                    else if (instructions.find(vformat("{}|{}", make_format_args(*next, *current))) != instructions.end())
                    {
                        auto res = instructions.find(vformat("{}|{}", make_format_args(*next, *current)));
                        if (*current == res->second.after)
                        {
                            valid = false;
                            int temp = *next;
                            *next = *current;
                            *current = temp;
                        }
                    }
                    ++next;
                }
                ++current;
            }

            int middle_index = static_cast<int>(ceil(static_cast<double>(updates.size()) / 2.0));

            if (valid)
            {
                res += updates.at(middle_index - 1);
            }
            else
            {
                res2 += updates.at(middle_index - 1);
            }
        }
    }

    in.close();

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
