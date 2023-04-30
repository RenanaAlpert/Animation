#pragma once
#include "Rectangle.h"
#include "Point.h"

namespace experis
{

class Squer : public Rectangle
{
public:
	explicit Squer() = delete;
	//explicit Squer(char a_brash, CoordType a_leftTopX, CoordType a_leftTopY, CoordType a_rightDownX, CoordType a_rightDownY);
	explicit Squer(char a_brash, CoordType a_leftTopX, CoordType a_leftTopY, int a_lengthSide);
	Squer(const Squer& a_other);
	Squer& operator=(const Squer& a_other) = delete;
	virtual ~Squer() = default;
};

} //experis