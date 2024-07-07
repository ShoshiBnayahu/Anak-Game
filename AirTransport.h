#pragma once
#include "Tile.h"
enum class AirTransportType {
	Helicopter
};

class AirTransport
{
protected:
	AirTransportType type;
	std::pair<int, int> location;


public:
	AirTransport(int x, int y, AirTransportType t);
	AirTransportType  getType() const { return type; }
	std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(AirTransportType type);

};

