/*********************************************************
 *
 * Brainfuck interpreter by Andrey A. Ugolnik
 * Copyright (c) 2011. All Rights Reserved.
 * andrey@ugolnik.info
 * http://www.ugolnik,info
 *
 *********************************************************/

#include "parser.h"

#include <cassert>
#include <cstdio>

void cParser::SetScript(const char* script)
{
    m_script = script;
}

void cParser::SetInput(const char* input)
{
    m_input = input;
}

bool cParser::Parse()
{
    if(m_script == nullptr)
    {
        return false;
    }

    m_data.clear();
    m_data.push_back(0);
    m_dataPos = 0;
    m_inputPos = 0;

    interprete(m_script);

    return true;
}

void cParser::interprete(const char* script)
{
    for( ; *script != 0; )
    {
        const char cmd = *script;

        switch(cmd)
        {
        case '<':
            if(m_dataPos > 0)
            {
                m_dataPos--;
            }
            else
            {
                m_data.insert(m_data.begin(), 0);
            }
            break;

        case '>':
            m_dataPos++;
            if(m_dataPos == m_data.size())
            {
                m_data.push_back(0);
            }
            break;

        case '+':
            m_data[m_dataPos]++;
            break;

        case '-':
            m_data[m_dataPos]--;
            break;

        case '.':
            printf("%c", m_data[m_dataPos]);
            break;

        case ',':
            if(m_input != 0 && m_input[m_inputPos] != 0)
            {
                m_data[m_dataPos] = m_input[m_inputPos++];
            }
            else
            {
                m_data[m_dataPos] = 0;
            }
            break;

        case '[':
            if(m_data[m_dataPos] == 0)
            {
                size_t brackets = 0;
                for( ; *script != 0; script++)
                {
                    const char nextCmd = *script;
                    if(nextCmd == '[')
                    {
                        brackets++;
                    }
                    else if(nextCmd == ']')
                    {
                        brackets--;
                        if(brackets == 0)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                m_stack.push_back(script);
            }
            break;

        case ']':
            if(m_data[m_dataPos] != 0)
            {
                assert(m_stack.size() != 0);
                script = m_stack.back();
                m_stack.pop_back();
                continue;
            }
            break;
        }

        script++;
    }
}

