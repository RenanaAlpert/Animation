#include "Circle.h"
#include "canvas_inl.hpp"

namespace experis
{

Circle::Circle(char a_brash, CoordType a_x, CoordType a_y, size_t a_radius)
	: Shape(a_brash), m_center(a_x, a_y), m_radius(a_radius)
{
}

Circle::Circle(const Circle& a_other)
	:Shape(a_other), m_center(a_other.m_center.GetX(), a_other.m_center.GetY()), m_radius(a_other.m_radius)
{
}

void Circle::MoveBy(CoordType a_deltaX, CoordType a_deltaY)
{
	this->m_center.MoveBy(a_deltaX, a_deltaY);
}

void Circle::Draw(ascii::ColoredCanvas& a_canvas) const
{
	ascii::DrawCircle(a_canvas, this->m_brush, this->m_fg, this->m_bg, this->m_center, m_radius);
}

Circle* Circle::Copy() const
{
	Circle* newCircle = new Circle{*this};
	return newCircle;
}

} // experis