/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#pragma once

#include <cstddef>
#include <vector>

class cParser final
{
public:
    cParser(const char* script, const char* input);

    void setScript(const char* script);
    void setInput(const char* input);

    bool parse();

private:
    void interprete(const char* script);

private:
    const char* m_script = nullptr;
    const char* m_input = nullptr;

private:
    size_t m_inputPos = 0;
    size_t m_dataPos = 0;
    std::vector<char> m_data;
    std::vector<const char*> m_stack;
};
