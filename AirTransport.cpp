#include "AirTransport.h"

AirTransport::AirTransport(int x, int y, AirTransportType t) :location(std::make_pair(x, y)), type(t) {}

std::string  AirTransport::typeToString(AirTransportType type)
{
	switch (type) {
	case AirTransportType::Helicopter:
		return "Helicopter";
	default:
		return "Unknown";
	}
}