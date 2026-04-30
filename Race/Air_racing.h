#ifndef AIR_RACING_H
#define AIR_RACING_H

#include "Race.h"

namespace Race_lib
{
    class RACE_API Air_Racing : public Race
    {
    private:
        int numbers[3];

    public:
        Air_Racing();
        void printRaceType() const;
        bool isValidChoice(int choice) const;    
    };
}

#endif