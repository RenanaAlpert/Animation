#include "AnimationStep.h"

namespace experis
{

ShapeActionFuncHolder::ShapeActionFuncHolder(const ShapeActionFuncHolder& a_other)
	: m_func(a_other.m_func->Clone())
{
}

void ShapeActionFuncHolder::operator()(Shape& a_shape) 
{
	m_func->Do(a_shape);
}

}