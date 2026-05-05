#ifndef EAGLE_H
#define EAGLE_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Eagle : public Air
	{
	public:
		Eagle() = delete;
		explicit Eagle(int way);
		virtual ~Eagle() = default;
		double find_time() const override;
	};
}

#endif