/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <stack>

class CParser
{
public:
    CParser();
    virtual ~CParser();

    void SetScript(const char* script);
    void SetInput(const char* input);
    bool Parse();

private:
    const char* m_script;
    const char* m_input;
    std::vector<unsigned char> m_field;
    std::stack<int> m_stack;
};

#endif //PARSER_H

