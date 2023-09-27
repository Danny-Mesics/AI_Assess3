#include "Sequence.h"
#include "Agent.h"
#include "Behaviour.h"



AIForGames::Status AIForGames::Sequence::Update(Agent* agent, float deltaTime)
{
	for (AIForGames::Behaviour* b : m_children) {
		if (b->Update(agent, deltaTime) == BH_FAILURE)
			return BH_FAILURE;
	}
	return BH_SUCCESS;
}
