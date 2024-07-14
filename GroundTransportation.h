#pragma once
#include "Tile.h"
#include "Location.h"

enum class GroundTransportationType {
	Car,
	Truck
};

class GroundTransportation :public Resource,public Location
{
private:
	GroundTransportationType type;
	static int carCounter;
	static int truckCounter;
	//std::pair<int, int> location;


public:
	GroundTransportation(GroundTransportationType t ,std::pair<int,int>l)
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		;
	//GroundTransportation(int x, int y, GroundTransportationType t);
	GroundTransportationType  getType() const { return type; }
	void setType(GroundTransportationType t) { type = t; }
	void addResource(std::string resource, int amount) override;
	//std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(GroundTransportationType type);
	static int getCarCounter() ;
	static int getTruckCounter() ;
};

