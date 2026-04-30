#ifndef OFF_ROAD_BOOTS_H
#define OFF_ROAD_BOOTS_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Off_road_boots : public Ground
	{
	public:
		Off_road_boots(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif