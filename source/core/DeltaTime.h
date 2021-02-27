#pragma once

#include "Clock.h"

class DeltaTime
{
public:

	DeltaTime() = default;

public:

	void update();

public:

	void setRestart(const sf::Time& time);
	void setElapsed(const sf::Time& time);
	void setTimerStart(const sf::Time& time);
	void setTimerEnd(const sf::Time& time);

public:

	sf::Time		getRestart();
	sf::Time		getElapsed();
	sf::Time		getTimerStart();
	sf::Time		getTimerEnd();
	unsigned int	getFramesPerSecond();

private:

	Clock			m_Clock					= Clock();
	sf::Time		m_Restart				= sf::Time();
	sf::Time		m_Elapsed				= sf::Time();
	sf::Time		m_TimerStart			= sf::Time();
	sf::Time		m_TimerEnd				= sf::Time();
	sf::Time		m_FramesPerSecondTimer	= sf::Time();
	unsigned int	m_FrameCounter			= 0;
	unsigned int	m_FramesPerSecond		= 0;

};

