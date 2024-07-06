
#pragma once
#include "GroundObject.h"
#include "People.h"
#include "Tile.h"
class Coordinate
{
private:
	Tile* tile;
	GroundObject* groundObject;
	;
	People* people;
public:
	Coordinate(Tile * t): tile(t) {}
	Tile*  getTile() const {
		return tile;
	}
	GroundObject* getGroundObject() const {
		return groundObject;
	}
	void setGroundObject(GroundObject* c) {
		groundObject = c;
	}
};
