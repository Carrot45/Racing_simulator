#include <iostream>
#include "Eagle.h"

namespace Transport_lib
{
    Eagle::Eagle(int way)
        : Air(way) {
    }
    double Eagle::find_time() const
    {
        double initial_speed = 8.0; 
        double reduction_percent = 0.06; 

        double reduced_distance = way * (1 - reduction_percent);
                
        double time = reduced_distance / initial_speed;

        return time;
    }
}