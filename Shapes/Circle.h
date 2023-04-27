#pragma once
#include "Shape.h"
#include "Point.h"

namespace experis
{

class Circle : public Shape
{
public:
	explicit Circle() = delete;
	explicit Circle(char a_brash, CoordType a_x, CoordType a_y, size_t a_radius);
	Circle(const Circle& a_other);
	Circle& operator=(const Circle& a_other) = delete;
	virtual ~Circle() = default;

	virtual void MoveBy(CoordType a_deltaX, CoordType a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual Circle* Copy() const;

private:
	Point m_center;
	size_t m_radius;
};

} // experis