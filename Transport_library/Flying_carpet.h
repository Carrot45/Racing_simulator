#ifndef FLYING_CARPET_H
#define FLYING_CARPET_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Flying_carpet : public Air
	{
	public:
		Flying_carpet(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif