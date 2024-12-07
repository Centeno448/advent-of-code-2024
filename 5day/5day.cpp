#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include <vector>
#include <regex>

#include "5day.h"

using namespace std;

struct Instruction
{
    Instruction(int b, int a) : before(b), after(a) {}
    int before;
    int after;
};

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

    std::vector<Instruction> instructions;

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

            instructions.emplace_back(before, after);
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

                std::cout << page_num << ",";
            }

            int page_num = stoi(line);
            updates.push_back(page_num);
        }
    }

    in.close();

    std::cout << format("day 3-1 res: {}", res) << std::endl;
    std::cout << format("day 3-2 res: {}", res2) << std::endl;
}
