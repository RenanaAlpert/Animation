#pragma once
#include "colored_canvas.hpp"
#include <string>

namespace experis
{

class Shape
{
public:
	using CoordType = short;
	using Color = ascii::ColoredCanvas::Color;

	explicit Shape() = delete;
	explicit Shape(char a_brash)
		: m_brush(a_brash), m_bg(Color::BLACK), m_fg(Color::WHITE)
	{
	};
	Shape(const Shape& a_other)
		: m_brush(a_other.m_brush), m_bg(a_other.m_bg), m_fg(a_other.m_fg)
	{
	};
	Shape& operator=(const Shape& a_other) = delete;
	virtual ~Shape() = default;

	void SetFg(Color a_color) {this->m_fg = a_color;}
	void SetBg(Color a_color) {this->m_bg = a_color;}
	void SetBrush(char a_brush) {this->m_brush = a_brush;}
	virtual void MoveBy(CoordType deltaX, CoordType deltaY) = 0;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const = 0;
	virtual Shape* Copy() const = 0;
	virtual std::string ConvertToString() const = 0;
	//char GetBrush() const {return this->m_brush;}

protected:
	char m_brush;
	Color m_fg;
	Color m_bg;
};

} // experis