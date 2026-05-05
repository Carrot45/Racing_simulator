#include <iostream>
#include "Off_road_boots.h"

namespace Transport_lib
{
    Off_road_boots::Off_road_boots(int way)
        : Ground(way) {
    }
    double Off_road_boots::find_time() const
    {
        double common_time = way / 6.0;
        int number_of_pauses = static_cast<int>(common_time / 60);
        if (number_of_pauses <= 1)
        {
            return common_time;
        }
        else if (number_of_pauses <= 2)
        {
            return common_time + 10.0;
        }
        else
        {
            return (common_time + 10.0 + (number_of_pauses - 1) * 5.0);
        }
    }
}