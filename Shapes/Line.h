#pragma once
#include "Shape.h"
#include "Point.h"

namespace experis
{

class Line : public Shape
{
public:
	explicit Line() = delete;
	explicit Line(char a_brash, CoordType a_startX, CoordType a_startY, CoordType a_endX, CoordType a_endY);
	Line(const Line& a_other);
	Line& operator=(const Line& a_other) = delete;
	virtual ~Line() = default;

	virtual void MoveBy(CoordType a_deltaX, CoordType a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual Line* Copy() const;

private:
	Point m_start;
	Point m_end;
};

} // experis