#include "LightObject.h"

int LightObject::GlobalID = 0;

LightObject::LightObject() 
{
	uniqueID = GlobalID;
	GlobalID++;
}