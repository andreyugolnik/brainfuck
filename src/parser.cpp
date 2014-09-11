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
#include <iostream>

    CParser::CParser()
    : m_script(0)
      , m_input(0)
{
}

CParser::~CParser()
{
}

void CParser::SetScript(const char* script)
{
    m_script = script;
}

void CParser::SetInput(const char* input)
{
    m_input = input;
}

bool CParser::Parse()
{
    if(m_script == 0)
    {
        return false;
    }

    size_t pos_in_field = 0;
    m_field.push_back(0);
    int pos_in_field_in_input = 0;

    for(int pos_in_script = 0; m_script[pos_in_script] != 0; )
    {
        switch(m_script[pos_in_script])
        {
        case '<':
            if(pos_in_field > 0)
            {
                pos_in_field--;
            }
            else
            {
                m_field.insert(m_field.begin(), 0);
            }
            break;

        case '>':
            pos_in_field++;
            if(pos_in_field > m_field.size() - 1)
            {
                m_field.push_back(0);
            }
            break;

        case '+':
            m_field[pos_in_field]++;
            break;

        case '-':
            m_field[pos_in_field]--;
            break;

        case '.':
            printf("%c", m_field[pos_in_field]);
            break;

        case ',':
            if(m_input != 0 && m_input[pos_in_field_in_input] != 0)
            {
                m_field[pos_in_field] = m_input[pos_in_field_in_input++];
            }
            else
            {
                m_field[pos_in_field] = 0;
            }
            break;

        case '[':
            if(m_field[pos_in_field] == 0)
            {
                int brackets = 0;
                for( ; m_script[pos_in_script] != 0; pos_in_script++)
                {
                    if(m_script[pos_in_script] == '[')
                    {
                        brackets++;
                    }
                    else if(m_script[pos_in_script] == ']')
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
                m_stack.push(pos_in_script);
            }
            break;

        case ']':
            if(m_stack.size() != 0)
            {
                int pos = m_stack.top();
                // we should pop amyway
                m_stack.pop();
                if(m_field[pos_in_field] != 0)
                {
                    pos_in_script = pos;
                    continue;
                }
            }
            else
            {
                // something wrong or opening '[' absent.
            }
            break;
        }

        pos_in_script++;
    }

    std::cout << std::endl;

    return true;
}

