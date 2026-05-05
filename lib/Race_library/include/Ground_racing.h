#ifndef GROUND_RACING_H
#define GROUND_RACING_H
#include "Race_library.h"

namespace Race_lib
{
    class RACE_API Ground_Racing : public Race_library
    {
    private:
        int numbers[4];

    public:
        Ground_Racing();
        ~Ground_Racing() = default;
        bool isValidChoice(int choice) const override;
    };
}

#endif