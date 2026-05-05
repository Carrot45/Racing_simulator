#include <iostream>
#include "Swift_Camel.h"

namespace Transport_lib
{
    Swift_Camel::Swift_Camel(int way)
        : Ground(way) {
    }
    double Swift_Camel::find_time() const
    {
        double common_time = way / 40.0;
        int number_of_pauses = static_cast<int>(common_time / 10);
        if (number_of_pauses <= 1)
        {
            return common_time;
        }
        else if (number_of_pauses <= 2)
        {
            return common_time + 5.0;
        }
        else if (number_of_pauses <= 3)
        {
            return common_time + 11.5;
        }
        else
        {
            return (common_time + 11.5 + (number_of_pauses - 1) * 8.0);
        }
    }
}