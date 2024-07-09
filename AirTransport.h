#pragma once
#include "Tile.h"
enum class AirTransportType {
	Helicopter
};

class AirTransport :public Resource
{
protected:
	AirTransportType type;
	//std::pair<int, int> location;


public:
	AirTransport( AirTransportType t);
	AirTransportType  getType() const { return type; }
	void addResource(std::string resource, int amount) override;
	//std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(AirTransportType type);

};

