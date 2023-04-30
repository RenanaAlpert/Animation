#include "Rectangle.h"
#include "canvas_inl.hpp"

namespace experis
{

Rectangle::Rectangle(char a_brash, CoordType a_leftTopX, CoordType a_leftTopY, CoordType a_rightDownX, CoordType a_rightDownY)
	: Shape(a_brash), m_leftTop{a_leftTopX, a_leftTopY}, m_rightDown{a_rightDownX, a_rightDownY}
{
}

Rectangle::Rectangle(const Rectangle& a_other)
	: Shape(a_other), m_leftTop{a_other.m_leftTop.GetX(), a_other.m_leftTop.GetY()}, m_rightDown{a_other.m_rightDown.GetX(), a_other.m_rightDown.GetY()}
{
}

void Rectangle::MoveBy(CoordType a_deltaX, CoordType a_deltaY)
{
	this->m_leftTop.MoveBy(a_deltaX, a_deltaY);
	this->m_rightDown.MoveBy(a_deltaX, a_deltaY);
}

void Rectangle::Draw(ascii::ColoredCanvas& a_canvas) const
{
	ascii::DrawLine(a_canvas, this->m_brush, this->m_fg, this->m_bg, 
		Point{this->m_leftTop.GetX(), this->m_leftTop.GetY()}, Point{this->m_leftTop.GetX(), this->m_rightDown.GetY()});
	ascii::DrawLine(a_canvas, this->m_brush, this->m_fg, this->m_bg, 
		Point{this->m_leftTop.GetX(), this->m_rightDown.GetY()}, Point{this->m_rightDown.GetX(), this->m_rightDown.GetY()});
	ascii::DrawLine(a_canvas, this->m_brush, this->m_fg, this->m_bg, 
		Point{this->m_rightDown.GetX(), this->m_leftTop.GetY()}, Point{this->m_rightDown.GetX(), this->m_rightDown.GetY()});
	ascii::DrawLine(a_canvas, this->m_brush, this->m_fg, this->m_bg, 
		Point{this->m_leftTop.GetX(), this->m_leftTop.GetY()}, Point{this->m_rightDown.GetX(), this->m_leftTop.GetY()});
}

Rectangle* Rectangle::Copy() const
{
	Rectangle* newLine = new Rectangle{*this};
	return newLine;
}

} // experis