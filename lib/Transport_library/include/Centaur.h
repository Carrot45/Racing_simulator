#ifndef CENTAUR_H
#define CENTAUR_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Centaur : public Ground
	{
	public:
		Centaur() = delete;
		explicit Centaur(int way);
		virtual ~Centaur() = default;
		double find_time() const override;
	};
}

#endif