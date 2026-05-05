#include "Air_Racing.h"
#include <iostream>

namespace Race_lib
{
    Air_Racing::Air_Racing()
    {
        numbers[0] = 2;
        numbers[1] = 5;
        numbers[2] = 7;
    }

    bool Air_Racing::isValidChoice(int choice) const
    {
        for (int i = 0; i < 3; i++)
        {
            if (numbers[i] == choice)
            {
                return true; 
            }
        }
        return false; 
    }
}