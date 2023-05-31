#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Group.h"

namespace experis
{

struct AddShapeFromOutside
{
	virtual void Add(Group& a_group, const std::vector<std::string>& a_data) const = 0 ;
};

struct AddCircle : public AddShapeFromOutside
{
	virtual void Add(Group& a_group, const std::vector<std::string>& a_data) const override;
};

struct AddLine : public AddShapeFromOutside
{
	virtual void Add(Group& a_group, const std::vector<std::string>& a_data) const override;
};

struct AddRectangle : public AddShapeFromOutside
{
	virtual void Add(Group& a_group, const std::vector<std::string>& a_data) const override;
};

namespace detail
{
	static const AddCircle CIRCLE;
	static const AddLine LINE;
	static const AddRectangle RECTANGLE;
}

static const std::unordered_map<std::string, const AddShapeFromOutside*> PARSE_SHAPES = {
	{"Circle", &detail::CIRCLE},
	{"Line", &detail::LINE},
	{"Rectangle", &detail::RECTANGLE}
};

} // experis