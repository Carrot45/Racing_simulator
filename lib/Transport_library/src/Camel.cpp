#include <iostream>
#include "Camel.h"

namespace Transport_lib  
{
    Camel::Camel(int way)
        : Ground(way) {
    }
    double Camel::find_time() const
    {
        double common_time = way / 10.0;
        int number_of_pauses = static_cast<int>(common_time / 30);
        if (number_of_pauses <= 1)
        {
            return common_time;
        }
        else if (number_of_pauses <= 2)
        {
            return common_time + 5.0;
        }
        else
        {
            return (common_time + 5.0 + (number_of_pauses - 1) * 8.0);
        }
    }
}