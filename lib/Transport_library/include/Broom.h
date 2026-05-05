#ifndef BROOM_H
#define BROOM_H

#include "Air.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Broom : public Air
	{
	public:
		Broom() = delete;
		explicit Broom(int way);
		double find_time() const override;
	};
}

#endif