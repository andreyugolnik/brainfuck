/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#include "parser.h"

#include <cstdio>
#include <cstring>
#include <vector>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        ::printf("Copyright (c) 2011, 2015, 2017 Andrey A. Ugolnik.\n");
        ::printf("Usage:\n");
        auto p = ::strrchr(argv[0], '/');
        ::printf("  %s SCRIPT_FILENAME [\"INPUT\"]\n", p ? p + 1 : argv[0]);

        return -1;
    }

    auto f = ::fopen(argv[1], "r");
    if (f != nullptr)
    {
        ::fseek(f, 0, SEEK_END);
        auto len = ::ftell(f);
        ::fseek(f, 0, SEEK_SET);

        std::vector<char> script(len + 1);
        auto data = script.data();
        if ((len == (long)::fread(data, 1, len, f)) != 0)
        {
            data[len] = 0;

            cParser parser(data, argc > 2 ? argv[2] : nullptr);
            parser.parse();
        }

        ::fclose(f);
    }

    return 0;
}
