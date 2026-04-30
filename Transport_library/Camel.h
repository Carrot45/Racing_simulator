#ifndef CAMEL_H
#define CAMEL_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Camel : public Air
	{
	public:
		Camel(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif