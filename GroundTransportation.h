#pragma once
#include "Tile.h"
enum class GroundTransportationType {
	Car,
	Truck
};

class GroundTransportation
{
protected:
	GroundTransportationType type;
	std::pair<int, int> location;


public:
	GroundTransportation(int x, int y, GroundTransportationType t);
	GroundTransportationType  getType() const { return type; }
	std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(GroundTransportationType type);

};

