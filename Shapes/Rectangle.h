#pragma once
#include "Shape.h"
#include "Point.h"

namespace experis
{

class Rectangle : public Shape
{
public:
	explicit Rectangle() = delete;
	explicit Rectangle(char a_brash, CoordType a_leftTopX, CoordType a_leftTopY, CoordType a_rightDownX, CoordType a_rightDownY);
	Rectangle(const Rectangle& a_other);
	Rectangle& operator=(const Rectangle& a_other) = delete;
	virtual ~Rectangle() = default;

	virtual void MoveBy(CoordType a_deltaX, CoordType a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual Rectangle* Copy() const;

private:
	Point m_leftTop;
	Point m_rightDown;
};