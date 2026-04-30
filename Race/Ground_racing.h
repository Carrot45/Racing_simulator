#ifndef GROUND_RACING_H
#define GROUND_RACING_H

#include "Race.h"

namespace Race_lib
{
    class RACE_API Ground_Racing : public Race
    {
    private:
        int numbers[4];

    public:
        Ground_Racing();
        void printRaceType() const override;
        bool isValidChoice(int choice) const override;
    };
}

#endif