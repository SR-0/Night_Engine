#include "Update.h"

void Update::execute()
{
	updateAll();
}

void Update::updateAll()
{
	updateDelta();
	updateEvent();
	updateState();
}

void Update::updateDelta()
{
	// update all critical time measurements
	m_DeltaTime->update();
}

void Update::updateEvent()
{
	// temp event for this frame
	sf::Event event;

	// poll events for this frame (e.g. window focus, key pressed, ect..)
	while (m_RenderWindow->pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			{
				if (!m_InhibitPressed)
				{
					switch (event.key.code) // section will get much bigger
					{
						case Input::Keyboard::Escape:
						{
							m_RenderWindow->close();
						}
						break;
					}
				}
			}
			break;

			case sf::Event::KeyReleased:
			{
				if (!m_InhibitReleased)
				{
					switch (event.key.code) // section will get much bigger
					{
						case Input::Keyboard::Escape:
						{
							// TO DO
						}
						break;
					}
				}
			}
			break;
		}
	}
}

void Update::updateState()
{
	switch (*m_CurrentState)
	{
		case GAME_STATE::TITLE:
		{
			updateTitle();
		}
		break;

		case GAME_STATE::LOAD:
		{
			updateLoad();
		}
		break;

		case GAME_STATE::PLAY:
		{
			updatePlay();
		}
		break;

		case GAME_STATE::PAUSE:
		{
			updatePause();
		}
		break;

		case GAME_STATE::SAVE:
		{
			updateSave();
		}
		break;

		case GAME_STATE::EXIT:
		{
			updateExit();
		}
		break;
	}
}

void Update::updateTitle()
{
	// pointers for shorter code (section will get a lot bigger)
	static RectangleShape* background		= &m_RectangleShapes->get("Background");
	static RectangleShape* buttonPlay		= &m_RectangleShapes->get("ButtonPlay");
	static RectangleShape* buttonGameMode	= &m_RectangleShapes->get("ButtonGameMode");
	static RectangleShape* buttonScreenMode	= &m_RectangleShapes->get("ButtonScreenMode");
	static RectangleShape* buttonResolution	= &m_RectangleShapes->get("ButtonResolution");
	static RectangleShape* buttonQuit		= &m_RectangleShapes->get("ButtonQuit");
	static RectangleShape* splashScreen		= &m_RectangleShapes->get("SplashScreen");

	if (!splashScreen->isTransparent())
	{
		splashScreen->fadeOut(fadeSpeed);
	}
	else if (!background->isOpaque())
	{
		background->fadeIn(fadeSpeed);
	}
	else if (buttonPlay->getOpacity() < 100.f)
	{
		buttonPlay->fadeIn(fadeSpeed);
		buttonGameMode->fadeIn(fadeSpeed);
		buttonScreenMode->fadeIn(fadeSpeed);
		buttonResolution->fadeIn(fadeSpeed);
		buttonQuit->fadeIn(fadeSpeed);
	}
	else
	{
		// TO DO
	}
}

void Update::updateLoad()
{
	// TO DO
}

void Update::updatePlay()
{
	// TO DO
}

void Update::updatePause()
{
	// TO DO
}

void Update::updateSave()
{
	// TO DO
}

void Update::updateExit()
{
	// TO DO
}
