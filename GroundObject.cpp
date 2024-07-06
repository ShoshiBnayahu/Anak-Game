#include "GroundObject.h"

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