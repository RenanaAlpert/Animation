#pragma once
#include <vector>
#include "AnimationStep.h"

namespace experis
{

class Animation
{
public:
	explicit Animation() = default;
	Animation(const Animation& a_other) = delete;
	Animation& operator=(const Animation& a_other) = delete;
	~Animation();

	bool HasAnimation() const;
	void Add(BaseAnimationStep* a_animSpep);
	Animation& operator++();

private:
	std::vector<BaseAnimationStep*> m_moves;
	std::pair<int, int> m_nextStep;
};

}