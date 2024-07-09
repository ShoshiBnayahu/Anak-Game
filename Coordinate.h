
#pragma once
#include "GroundObject.h"
#include "People.h"
#include "Tile.h"
#include "GroundTransportation.h"
#include "AirTransport.h"

class Coordinate
{
private:
	Tile* tile;
	GroundObject* groundObject;
	People* people;
	GroundTransportation* groundTransportation;
	AirTransport* airTransport;
public:
	Coordinate(Tile * t): tile(t) {}
	Tile* getTile() const { return tile; }
	GroundObject* getGroundObject() const { return groundObject; }
	void setGroundObject(GroundObject* c) { groundObject = c; }
	People* getPeople() const {return people;}
	void setPeople(People* p) { people = p; }
	GroundTransportation* getGroundTransportation() const { return groundTransportation; }
	void setGroundTransportation(GroundTransportation* gt) { groundTransportation = gt; }
    AirTransport* getAirTransport() const { return airTransport; }
    void setAirTransport(AirTransport* at) { airTransport = at; }
        

};
