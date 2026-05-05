#include <iostream>
#include "Flying_carpet.h"

namespace Transport_lib
{
    Flying_carpet::Flying_carpet(int way)
        : Air(way) {
    }
    double Flying_carpet::find_time() const
    {
        double reduction_percent{};

        if (way < 1000)
            reduction_percent = 0.0;
        else if (way < 5000)
            reduction_percent = 0.03;
        else if (way < 10000)
            reduction_percent = 0.10;
        else
            reduction_percent = 0.05;

        return ((way * (1 - reduction_percent)) / 10.0);
    }
}