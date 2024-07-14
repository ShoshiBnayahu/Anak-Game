#pragma once
#include "Tile.h"
#include "Location.h"

enum class GroundObjectType {
    City,
    Village,
	Road
};

class GroundObject:public Location
{
protected:
	GroundObjectType type;
	std::pair<int, int> location;
	bool isComplate;

public:
	GroundObject(GroundObjectType t, bool isComplate, std::pair<int, int>l);
	GroundObjectType  getType() const { return type; }
	virtual void makeEmpty() = 0;
	std::pair<int, int> getLocation() const { return location; }
	static std::string typeToString(GroundObjectType type);
	bool isComplete() { return isComplate; }
		
};

