#include "Air_and_ground_racing.h"
#include <iostream>

namespace Race_lib
{
    Air_and_ground_racing::Air_and_ground_racing()
    {
        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;
        numbers[3] = 4;
        numbers[4] = 5;
        numbers[5] = 6;
        numbers[6] = 7;
    }

    void Air_and_ground_racing::printRaceType() const
    {
        std::cout << "√онка дл€ наземного и воздушного транспорта." << std::endl;
    }
    bool Air_and_ground_racing::isValidChoice(int choice) const
    {
        for (int i = 0; i < 8; i++)
        {
            if (numbers[i] == choice)
            {
                return true;
            }
        }
        return false;
    }
}