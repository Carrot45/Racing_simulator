#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "Export.h"

namespace Transport_lib
{
    class TRANSPORT_API Transport
    {
    public:
        virtual ~Transport() {};
        virtual double find_time() const = 0;
    };
}

#endif