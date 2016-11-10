#include "Disc.h"

Disc::Disc()
{
	discType = 0;
}


Disc::~Disc()
{
}


char Disc::getDiscType()
{
	return discType;
}

void Disc::setDiscType(char type)
{
	this->discType = type;
}