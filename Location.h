#pragma once
#include "Tile.h"
class Location {
protected:
	std::pair<int, int>location;
public:
    Location(std::pair<int, int>l) :location(l){}
    std::pair<int, int> getLocation() const {
        return location;
    }
    void setLocation(std::pair<int, int>l) {
        location.first = l.first - 1;
        location.second = l.second - 1;
    }
};