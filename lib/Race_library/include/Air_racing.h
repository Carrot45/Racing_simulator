#ifndef AIR_RACING_H
#define AIR_RACING_H
#include "Race_library.h"

namespace Race_lib
{
    class RACE_API Air_Racing : public Race_library
    {
    private:
        int numbers[3];

    public:
        Air_Racing();
        virtual ~Air_Racing() = default;
        bool isValidChoice(int choice) const override;
    };
}

#endif