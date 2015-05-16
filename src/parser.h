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
#include <cstddef>

class cParser final
{
public:
    void SetScript(const char* script);
    void SetInput(const char* input);
    bool Parse();

private:
    void interprete(const char* script);

private:
    const char* m_script = nullptr;
    const char* m_input = nullptr;
    size_t m_inputPos = 0;
    size_t m_dataPos = 0;
    std::vector<char> m_data;
    std::vector<const char*> m_stack;
};

#endif //PARSER_H

