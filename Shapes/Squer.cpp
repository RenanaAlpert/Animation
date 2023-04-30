#include "Squer.h"

namespace experis
{

Squer::Squer(char a_brash, CoordType a_leftTopX, CoordType a_leftTopY, int a_lengthSide) 
	: Rectangle(a_brash, a_leftTopX, a_leftTopY, a_leftTopX + a_lengthSide, a_leftTopY + a_lengthSide)
{
}

Squer::Squer(const Squer& a_other) 
	: Rectangle(a_other) 
{
}

}