#include "Ground_Racing.h"
#include <iostream>

namespace Race_lib  
{
    Ground_Racing::Ground_Racing()
    {
        numbers[0] = 1;
        numbers[1] = 3;
        numbers[2] = 4;
        numbers[3] = 6;
    }
    
    bool Ground_Racing::isValidChoice(int choice) const
    {
        for (int i = 0; i < 4; i++)
        {
            if (numbers[i] == choice)
            {
                return true;
            }
        }
        return false;
    }
}