#include "Line.h"
#include "canvas_inl.hpp"

namespace experis
{

Line::Line(char a_brash, CoordType a_startX, CoordType a_startY, CoordType a_endX, CoordType a_endY)
	: Shape(a_brash), m_start{a_startX, a_startY}, m_end{a_endX, a_endY}
{
}

Line::Line(const Line& a_other)
	: Shape(a_other), m_start{a_other.m_start.GetX(), a_other.m_start.GetY()}, m_end{a_other.m_end.GetX(), a_other.m_end.GetY()}
{
}

void Line::MoveBy(CoordType a_deltaX, CoordType a_deltaY)
{
	this->m_start.MoveBy(a_deltaX, a_deltaY);
	this->m_end.MoveBy(a_deltaX, a_deltaY);
}

void Line::Draw(ascii::ColoredCanvas& a_canvas) const
{
	ascii::DrawLine(a_canvas, this->m_brush, this->m_fg, this->m_bg, this->m_start, this->m_end);
}

Line* Line::Copy() const
{
	Line* newLine = new Line{*this};
	return newLine;
}

} // experis