#include "Disc.h"

Disc::Disc()
{
	discType = '-';
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
	discType = type;
}