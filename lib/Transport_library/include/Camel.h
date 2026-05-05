#ifndef CAMEL_H
#define CAMEL_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Camel : public Ground
	{
	public:
		Camel() = delete;
		explicit Camel(int way);
		virtual ~Camel() = default;
		double find_time() const override;
	};
}

#endif