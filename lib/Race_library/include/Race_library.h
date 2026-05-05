#ifndef RACE_LIBRARY_H
#define RACE_LIBRARY_H

#include "Export_race.h"

namespace Race_lib
{
    class RACE_API Race_library
    {
    public:
        Race_library();
        virtual ~Race_library() = default;
        virtual bool isValidChoice(int choice) const = 0;
    };
}

#endif