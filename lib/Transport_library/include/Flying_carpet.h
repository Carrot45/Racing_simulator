#ifndef FLYING_CARPET_H
#define FLYING_CARPET_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Flying_carpet : public Air
	{
	public:
		Flying_carpet() = delete;
		explicit Flying_carpet(int way);		
		virtual ~Flying_carpet() = default;
		double find_time() const override;
	};
}

#endif