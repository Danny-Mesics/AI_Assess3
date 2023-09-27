#include "Behaviour.h"

AIForGames::Status AIForGames::Behaviour::Tick(Agent* agent, float deltaTime)
{
    if (m_eStatus != BH_RUNNING)
    {
        OnInitialize();
    }

    m_eStatus = Update(agent, deltaTime);

    if (m_eStatus != BH_RUNNING)
    {
        OnTerminate(m_eStatus);
    }
    return m_eStatus;
}

AIForGames::Status AIForGames::Behaviour::GetStatus() const
{
    return m_eStatus;
}
