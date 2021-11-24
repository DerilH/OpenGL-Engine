#include "RenderingObject.h"

int RenderingObject::GlobalID = 0;

RenderingObject::RenderingObject()
{
	uniqueID = GlobalID;
	GlobalID++;
}