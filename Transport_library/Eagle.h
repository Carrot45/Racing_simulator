#ifndef EAGLE_H
#define EAGLE_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Eagle : public Air
	{
	public:
		Eagle(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif