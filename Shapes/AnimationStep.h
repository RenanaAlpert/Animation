#pragma once
#include "Shape.h"

namespace experis
{

struct BaseAnimationStep
{
	virtual int GetSteps() = 0;
	virtual void Do() = 0;
};

template <typename func>
class AnimationStep : public BaseAnimationStep
{
public:
	explicit AnimationStep() = delete;
	explicit AnimationStep(Shape& a_shape, int a_steps, func a_funcStep);
	AnimationStep(const AnimationStep& a_other) = delete;
	AnimationStep& operator=(const AnimationStep& a_other) = delete;
	~AnimationStep();

	virtual int GetSteps() override;
	virtual void Do() override;

private:
	Shape& m_shape;
	int m_steps;
	func m_funcStep;
};

template <typename func>
AnimationStep<func>::AnimationStep(Shape& a_shape, int a_steps, func a_funcStep)
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