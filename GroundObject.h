#pragma once
#include "Tile.h"
enum class GroundObjectType {
    City,
    Village,
	Road
};

class GroundObject
{
protected:
	GroundObjectType type;
	std::pair<int, int> location;
	bool isComplate;
public:
	GroundObject(int x,int y, GroundObjectType t ,bool isComplate):location(std::make_pair(x, y)),type(t) ,isComplate(isComplate) {}
	GroundObjectType  getType() const {
		return type;
	}
	virtual void makeEmpty() = 0;
	std::pair<int, int> getLocation() const {
		return location;
	}
	static std::string typeToString(GroundObjectType type);

	bool isComplete() {
		return isComplate;
	}
};

