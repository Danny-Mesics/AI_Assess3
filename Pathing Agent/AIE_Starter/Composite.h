#pragma once
#include <vector>
#include "Behaviour.h"


namespace AIForGames
{
    // abstract base class for sequence and selector nodes
    class Composite : Behaviour
    {
    protected:
        std::vector<Behaviour*> m_children; //the behaviours to select/sequence

        virtual Status Update(Agent* agent, float deltaTime) = 0;
    };
}

