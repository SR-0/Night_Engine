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

void DeltaTime::setRestart(const sf::Time& time)
{
	m_Restart = time;
}

void DeltaTime::setElapsed(const sf::Time& time)
{
	m_Elapsed = time;
}

void DeltaTime::setTimerStart(const sf::Time& time)
{
	m_TimerStart = time;
}

void DeltaTime::setTimerEnd(const sf::Time& time)
{
	m_TimerEnd = time;
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
