#include <iostream>
#include "Eagle.h"

namespace Transport_lib
{
    Eagle::Eagle(int way)
        : Air(way) {
    }
    double Eagle::find_time() const
    {        
        double reduced_distance = way * 0.94;
                
        double time = reduced_distance / 8.0;

        return time;
    }
}