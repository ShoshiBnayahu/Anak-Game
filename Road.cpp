#include "Road.h"
int Road::roadCounter = 0;

Road::Road( GroundObjectType type, bool isComplate,std::pair<int,int>l) : GroundObject( type, isComplate,l)
{
	roadCounter++;
}

