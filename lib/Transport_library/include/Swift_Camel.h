#ifndef SWIFT_CAMEL_H
#define SWIFT_CAMEL_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Swift_Camel : public Ground
	{
	public:
		Swift_Camel() = delete;
		explicit Swift_Camel(int way);
		virtual ~Swift_Camel() = default;
		double find_time() const override;
	};
}

#endif
