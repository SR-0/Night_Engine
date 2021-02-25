#include "DeltaTime.h"

#include <iostream> // add text object later

void DeltaTime::update()
{
	m_FrameCounter++;

	m_Restart				=	m_Clock.restart();
	m_Elapsed				+=	m_Restart;
	m_FramesPerSecondTimer	+=	m_Restart;

	if (m_FramesPerSecondTimer.asSeconds() >= 1)
	{
		m_FramesPerSecond = m_FrameCounter;
		m_FramesPerSecondTimer = sf::Time::Zero;
		m_FrameCounter = 0;
	}
}

sf::Time DeltaTime::getRestart()
{
	return m_Restart;
}

sf::Time DeltaTime::getElapsed()
{
	return m_Elapsed;
}

sf::Time DeltaTime::getTimerStart()
{
	return m_TimerStart;
}

sf::Time DeltaTime::getTimerEnd()
{
	return m_TimerEnd;
}

unsigned int DeltaTime::getFramesPerSecond()
{
	return m_FramesPerSecond;
}
