#pragma once
#include "Shape.h"

namespace experis
{

struct BaseAnimationStep
{
	virtual int GetSteps() = 0;
	virtual void Do() = 0;
};

class AbstractFunction
{
public:
	explicit AbstractFunction() = default;
	AbstractFunction(const AbstractFunction& a_other) = delete;
	AbstractFunction& operator=(const AbstractFunction& a_other) = default;
	virtual ~AbstractFunction() = default;

	virtual void Do(Shape& a_shape) = 0;
	virtual AbstractFunction* Clone() = 0;
};

template <typename func>
class ShapeActionFunc : public AbstractFunction
{
public:
	ShapeActionFunc() = delete;
	ShapeActionFunc(func a_func)
		: m_func(a_func)
	{
	}
	ShapeActionFunc(const ShapeActionFunc& a_other) = delete;
	virtual ~ShapeActionFunc() = default;

	virtual void Do(Shape& a_shape) override {m_func(a_shape);}
	virtual AbstractFunction* Clone() override { return new ShapeActionFunc<func>{m_func}; }

private:
	func m_func;
};

class ShapeActionFuncHolder
{
public:
	explicit ShapeActionFuncHolder() = delete;
	template <typename func>
	ShapeActionFuncHolder(func a_func)
		: m_func(new ShapeActionFunc<func>{a_func})
	{
	}
	ShapeActionFuncHolder(const ShapeActionFuncHolder& a_other);
	ShapeActionFuncHolder& operator=(const ShapeActionFuncHolder& a_other) = delete;
	~ShapeActionFuncHolder() {delete m_func;};

	void operator()(Shape& a_shape);
	
private:
	AbstractFunction* m_func;
};

template <typename func>
class AnimationStep : public BaseAnimationStep
{
public:
	explicit AnimationStep() = delete;
	explicit AnimationStep(Shape& a_shape, int a_steps, ShapeActionFuncHolder a_funcStep);
	AnimationStep(const AnimationStep& a_other) = delete;
	AnimationStep& operator=(const AnimationStep& a_other) = delete;
	~AnimationStep();

	virtual int GetSteps() override;
	virtual void Do() override;

private:
	Shape& m_shape;
	int m_steps;
	ShapeActionFuncHolder m_funcStep;
};

template <typename func>
AnimationStep<func>::AnimationStep(Shape& a_shape, int a_steps, ShapeActionFuncHolder a_funcStep)
	: m_shape(a_shape), m_steps(a_steps), m_funcStep(a_funcStep)
{
}

template <typename func>
AnimationStep<func>::~AnimationStep()
{
}

template <typename func>
int AnimationStep<func>::GetSteps()
{
	return this->m_steps;
}

template <typename func>
void AnimationStep<func>::Do()
{
	this->m_funcStep(this->m_shape);
}

} // experis