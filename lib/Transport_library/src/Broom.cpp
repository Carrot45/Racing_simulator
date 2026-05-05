#include <iostream>
#include "Broom.h"

namespace Transport_lib
{
    Broom::Broom(int way)
        : Air(way) {}
  
    double Broom::find_time() const
    {
        double initial_speed = 20.0;
        int reduction_percent = static_cast<int>(way / 1000); 
        double reduced_distance = way * (1 - reduction_percent * 0.01);
        double time = reduced_distance / initial_speed;
        return time;
    }
}