#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include "./PrintTypes.h"

#define STACK_SIZE 30000

// Return `1` if an error occured
// Return `0` if the program went ok.
int BFProgram(std::vector<std::string> args)
{
    std::string Code = args[0];
    
    char ptrs[STACK_SIZE] = {0};
    std::size_t pointing = 0;
    bool isLooping = false;
    int innerLoops = 0;
    std::vector<int> loops;
    std::string res;

    for (std::size_t i = 0; i < Code.length(); i++)
    {
        const char curChar = Code[i];

        if (isLooping)
        {
            if (curChar == '[')
                innerLoops++;
            if (curChar == ']')
            {
                if (innerLoops == 0) isLooping = false;
                else innerLoops--;
            }
            continue;
        }

        switch (curChar)
        {
            case '>':
                if (pointing == STACK_SIZE)
                    break;
                ++pointing;
                break;

            case '<':
                if (pointing == 0)
                    break;
                --pointing;
                break;

            case '+':
                ++ptrs[pointing];
                break;

            case '-':
                --ptrs[pointing];
                break;

            case '.':
                res = res + ptrs[pointing];
                break;

            case ',':
                std::cin >> std::noskipws >> ptrs[pointing];
                break;

            case '[':
                if (ptrs[pointing] == 0)
                    isLooping = true;
                else
                    loops.push_back(i);
                break;

            case ']':
                if (ptrs[pointing] != 0)
                    i = loops.back();
                else
                    loops.pop_back();
                break;
        }
    }

    if (res == "")
    {
        PRINT_ERR("BF C++ : Empty Results!");
        return 1;
    }

    PRINT_OK("BF C++ : Results ::");
    PRINT_OK(res);

    return 0;
}
