#pragma once
#include "Composite.h"

namespace AIForGames
{
    class Selector :
        public Composite
    {
    public:
        virtual Status Update(Agent* agent, float deltaTime);
    };
}

