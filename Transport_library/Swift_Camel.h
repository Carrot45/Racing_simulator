#ifndef SWIFT_CAMEL_H
#define SWIFT_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Swift_Camel : public Ground
	{
	public:
		Swift_Camel(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif
