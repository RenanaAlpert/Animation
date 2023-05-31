#include "AddShapeFromOutside.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

namespace experis
{

void AddCircle::Add(Group& a_group, const std::vector<std::string>& a_data) const
{
	a_group.Add<Circle>(std::stoi(a_data.at(1)), std::stoi(a_data.at(2)), std::stoi(a_data.at(3)));
	a_group.Back()->SetBg(static_cast<Shape::Color>(std::stoi(a_data.at(4))));
	a_group.Back()->SetFg(static_cast<Shape::Color>(std::stoi(a_data.at(5))));
	a_group.Back()->SetBrush(a_data.at(6).at(0));
}

void AddLine::Add(Group& a_group, const std::vector<std::string>& a_data) const
{
	a_group.Add<Line>(std::stoi(a_data.at(1)), std::stoi(a_data.at(2)), std::stoi(a_data.at(3)), std::stoi(a_data.at(4)));
	a_group.Back()->SetBg(static_cast<Shape::Color>(std::stoi(a_data.at(5))));
	a_group.Back()->SetFg(static_cast<Shape::Color>(std::stoi(a_data.at(6))));
	a_group.Back()->SetBrush(a_data.at(7).at(0));
}

void AddRectangle::Add(Group& a_group, const std::vector<std::string>& a_data) const
{
	a_group.Add<Rectangle>(std::stoi(a_data.at(1)), std::stoi(a_data.at(2)), std::stoi(a_data.at(3)), std::stoi(a_data.at(4)));
	a_group.Back()->SetBg(static_cast<Shape::Color>(std::stoi(a_data.at(5))));
	a_group.Back()->SetFg(static_cast<Shape::Color>(std::stoi(a_data.at(6))));
	a_group.Back()->SetBrush(a_data.at(7).at(0));
}

}