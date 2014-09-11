/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#include "parser.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Copyright (c) 2011 'WE' Group / Andrey A. Ugolnik." << std::endl;
    if(argc < 2)
    {
        std::cout << "Usage:" << std::endl;
        const char* p = strrchr(argv[0], '/');
        std::cout << "  " << (p ? p + 1 : argv[0]) << " SCRIPT_FILENAME [\"INPUT\"]" << std::endl << std::endl;
        return -1;
    }

    std::cout << std::endl;

    FILE* f = fopen(argv[1], "r");
    if(f)
    {
        fseek(f, 0, SEEK_END);
        long len	= ftell(f);
        fseek(f, 0, SEEK_SET);

        char* script = new char[len + 1];
        if(len == (long)fread(script, 1, len, f))
        {
            script[len] = 0;

            CParser parser;
            parser.SetScript(script);
            parser.SetInput(argc > 2 ? argv[2] : 0);
            parser.Parse();
        }

        delete[] script;

        fclose(f);
    }

    return 0;
}

