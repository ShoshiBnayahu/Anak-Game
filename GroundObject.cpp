#include "GroundObject.h"

GroundObject::GroundObject(int x, int y, GroundObjectType t, bool isComplate) :location(std::make_pair(x, y)), type(t), isComplate(isComplate) {}

std::string  GroundObject::typeToString(GroundObjectType type)
{
	switch (type) {
	case GroundObjectType::City:
		return "City";
	case GroundObjectType::Village:
		return "Village";
	case GroundObjectType::Road:
		return "Road";
	default:
		return "Unknown";
	}
}