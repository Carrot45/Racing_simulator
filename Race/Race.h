#ifndef RACE_H
#define RACE_H

#include "Export_race.h"

namespace Race_lib
{
    class RACE_API Race
    {
    public:
        virtual ~Race() {};
        virtual void printRaceType() const = 0;
        virtual bool isValidChoice(int choice) const = 0;
    };
}

#endif