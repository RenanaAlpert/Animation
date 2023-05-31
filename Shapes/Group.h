#pragma once
#include "Shape.h"
#include "Point.h"
#include <vector>

namespace experis
{

class Group : public Shape
{
public:
	explicit Group() = delete;
	explicit Group(char a_brash);
	Group(const Group& a_other);
	Group& operator=(const Group& a_other) = delete;
	virtual ~Group();

	virtual void MoveBy(CoordType a_deltaX, CoordType a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual Group* Copy() const;
	virtual std::string ConvertToString() const override;
	template<typename shapeT>
	void Add(CoordType a_x, CoordType a_y, size_t a_length);
	template<typename shapeT>
	void Add(CoordType a_x1, CoordType a_y1, CoordType a_x2, CoordType a_y2);
	template<typename shapeT>
	void Add(const shapeT& a_shape);
	Shape* Back();

private:
	using Container = std::vector<Shape*>;

	Container m_group;
};

template<typename shapeT>
void Group::Add(CoordType a_x, CoordType a_y, size_t a_length)
{
	Shape* newShape = new shapeT{this->m_brush, a_x, a_y, a_length};
	this->m_group.push_back(newShape);
}

template<typename shapeT>
void Group::Add(CoordType a_x1, CoordType a_y1, CoordType a_x2, CoordType a_y2)
{
	Shape* newShape = new shapeT{this->m_brush, a_x1, a_y1, a_x2, a_y2};
	this->m_group.push_back(newShape);
}

template<typename shapeT>
void Add(const shapeT& a_shape)
{
	Shape* newShape = new shapeT{a_shape};
	this->m_group.push_back(newShape);
}

} // experis