#include <iostream>
#include "Ñentaur.h"

namespace Transport_lib
{
    Ñentaur::Ñentaur(int way)
        : Ground(way) {
    }
    double Ñentaur::find_time() const
    {
        double common_time = way / 15.0;
        int number_of_pauses = static_cast<int>(common_time / 8);
        if (number_of_pauses <= 1)
        {
            return common_time;
        }
        else
        {
            return (common_time + 2.0 + (number_of_pauses - 1) * 2.0);
        }
    }

    std::string Ñentaur::getName() const
    {
        return "Êåíòàâð";
    }

}