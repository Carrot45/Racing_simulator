#ifndef CENTAUR_H
#define CENTAUR_H

#include "Ground.h"
#include <string>

namespace Transport_lib
{
	class TRANSPORT_API Ñentaur : public Ground
	{
	public:
		Ñentaur(int way);
		double find_time() const override;
		std::string getName() const;
	};
}

#endif