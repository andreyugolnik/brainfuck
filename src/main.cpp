/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#include "parser.h"

#include <vector>
#include <cstdio>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Copyright (c) 2011 'WE' Group / Andrey A. Ugolnik.\n");
        printf("Copyright (c) 2015 Tiny Orange / Andrey A. Ugolnik.\n");
        printf("Usage:\n");
        const char* p = strrchr(argv[0], '/');
        printf("  %s SCRIPT_FILENAME [\"INPUT\"]\n", p ? p + 1 : argv[0]);
        return -1;
    }

    FILE* f = fopen(argv[1], "r");
    if(f)
    {
        fseek(f, 0, SEEK_END);
        long len = ftell(f);
        fseek(f, 0, SEEK_SET);

        std::vector<char> script(len + 1);
        if(len == (long)fread(&script[0], 1, len, f))
        {
            script[len] = 0;

            cParser parser;
            parser.SetScript(&script[0]);
            parser.SetInput(argc > 2 ? argv[2] : 0);
            parser.Parse();
        }

        fclose(f);
    }

    return 0;
}

