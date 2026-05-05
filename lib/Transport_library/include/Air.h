#ifndef AIR_H
#define AIR_H

#include "Transport.h"

namespace Transport_lib
{
    class TRANSPORT_API Air : public Transport
    {
    protected:
        int way{};

    public:
        Air() = delete;
        explicit Air(int way);
        virtual ~Air() = default;
    };
}

#endif