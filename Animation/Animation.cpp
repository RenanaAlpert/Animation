#include "Animation.h"
#include <cassert>

namespace experis
{

Animation::~Animation()
{
	for(BaseAnimationStep *anim : this->m_moves)
	{
		delete anim;
	}
}

bool Animation::HasAnimation() const
{
	return this->m_nextStep.first < m_moves.size();
}

void Animation::Add(BaseAnimationStep* a_animSpep)
{
	this->m_moves.push_back(a_animSpep);
}

Animation& Animation::operator++()
{
	assert(this->HasAnimation());
	this->m_moves.at(this->m_nextStep.first)->Do();

	++this->m_nextStep.second;
	if(this->m_nextStep.second == this->m_moves.at(this->m_nextStep.first)->GetSteps())
	{
		++this->m_nextStep.first;
		this->m_nextStep.second = 0;
	}
	return *this;
}

}
