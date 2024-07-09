#include "GroundTransportation.h"
//GroundTransportation::GroundTransportation(int x, int y, GroundTransportationType t) :location(std::make_pair(x, y)), type(t) {}
//GroundTransportation::GroundTransportation( GroundTransportationType t) : type(t) {}

std::string  GroundTransportation::typeToString(GroundTransportationType type)
{
	switch (type) {
	case GroundTransportationType::Car:
		return "Car";
	case GroundTransportationType::Truck:
		return "Truck";
	default:
		return "Unknown";
	}
}