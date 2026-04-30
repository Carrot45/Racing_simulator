#include <iostream>
#include "Air.h"

namespace Transport_lib
{
    Air::Air(int setspeed, int setcoefficient, int setway)
        : speed(setspeed), coefficient(setcoefficient), way(setway)
    {
    }
}