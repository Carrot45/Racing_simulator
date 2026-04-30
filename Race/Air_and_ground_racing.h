#ifndef AIR_AND_GROUND_RACING_H
#define AIR_AND_GROUND_RACING_H

#include "Race.h"

namespace Race_lib
{
    class RACE_API Air_and_ground_racing : public Race
    {
    private:
        int numbers[7];

    public:
        Air_and_ground_racing();
        void printRaceType() const;
        bool isValidChoice(int choice) const override;
    };
}

#endif