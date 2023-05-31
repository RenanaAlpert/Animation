#include "Group.h"
#include <sstream>
#include <fstream>

namespace experis
{

Group::Group(char a_brash)
	:Shape(a_brash), m_group{}
{
}

Group::Group(const Group& a_other)
	: Shape(a_other), m_group{}
{
	for(Shape *s : a_other.m_group)
	{
		this->m_group.push_back(s->Copy());
	}
}

Group::~Group()
{
	for(Shape *s : this->m_group)
	{
		delete s;
	}
}

void Group::MoveBy(CoordType a_deltaX, CoordType a_deltaY)
{
	for(Shape* s : this->m_group)
	{
		s->MoveBy(a_deltaX, a_deltaY);
	}
}

void Group::Draw(ascii::ColoredCanvas& a_canvas) const
{
	for(Shape* s : this->m_group)
	{
		s->Draw(a_canvas);
	}
}

Group* Group::Copy() const
{
	Group* newGroup = new Group{*this};
	return newGroup;
}

Shape* Group::Back()
{
	return this->m_group.back();
}

std::string Group::ConvertToString() const
{
	std::stringstream group;
	for(const Shape* s : this->m_group)
	{
		group << "\n" << s->ConvertToString();
	}
	return group.str();
}

}