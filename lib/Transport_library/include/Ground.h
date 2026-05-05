#ifndef GROUND_H
#define GROUND_H

#include "Export.h"
#include "Transport.h"

namespace Transport_lib
{
    class TRANSPORT_API Ground : public Transport
    {
    protected:
        int way{};

    public:
        Ground() = delete;
        explicit Ground(int way);
        virtual ~Ground() = default;
    };
}

#endif