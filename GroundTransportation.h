
#pragma once
#include "Tile.h"
enum class GroundTransportationType {
	Car,
	Truck
};

class GroundTransportation :public Resource
{
protected:
	GroundTransportationType type;
	//std::pair<int, int> location;


public:
	GroundTransportation();
	GroundTransportation(GroundTransportationType t);
	//GroundTransportation(int x, int y, GroundTransportationType t);
	GroundTransportationType  getType() const { return type; }
	void setType(GroundTransportationType t) { type = t; }
	void addResource(std::string resource, int amount) override;
	//std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(GroundTransportationType type);

};

