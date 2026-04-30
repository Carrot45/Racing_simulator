#ifndef AIR_H
#define AIR_H

#include "Transport.h"

namespace Transport_lib
{
    class TRANSPORT_API Air : public Transport
    {
    protected:
        int speed, coefficient, way;

    public:
        Air(int speed, int coefficient, int way);
        virtual double find_time() const = 0;
    };
}

#endif