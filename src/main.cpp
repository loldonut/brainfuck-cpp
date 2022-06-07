#include<iostream>
#include<string>
#include<vector>

#include "PrintTypes.h"
#include "Program.h"

int main(int argc, char** argv)
{
    std::vector<std::string> args;

    if (argc > 1)
    {
        args.assign(argv + 1, argv + argc);
    }
    else
    {
        PRINT_ERR("Need code input!");
        PRINT_ERR("Usage: bf \"<bf_code>\"");
        return 1;
    }

    return BFProgram(args);
}
