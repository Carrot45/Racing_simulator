#include <iostream>
#include "Broom.h"

namespace Transport_lib
{
    Broom::Broom(int way)
        : Air(way) {}
  
    double Broom::find_time() const
    {
        int reduction_percent = static_cast<int>(way / 1000); 
        double reduced_distance = way * (1 - reduction_percent * 0.01);
        double time = reduced_distance / 20.0;
        return time;
    }
}