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
			if (!Input::InhibitKeyboard)
			{
				if (!Input::InhibitKeyboardPress)
				{
					case sf::Event::KeyPressed:
					{
						switch (event.key.code) // section will get much bigger
						{
							case Input::Keyboard::Escape:
							{
								if (*m_CurrentState == GAME_STATE::TITLE)
								{
									m_TitleState = TITLE_STATE::CHOICE_QUIT;
								}

								if (*m_CurrentState == GAME_STATE::PLAY)
								{
									m_PlayState = PLAY_STATE::QUIT;
								}
							}
							break;
						}
					}
					break;
				}

				if (!Input::InhibitKeyboardRelease)
				{
					case sf::Event::KeyReleased:
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
					break;
				}
			}

			if (!Input::InhibitMouse)
			{
				if (!Input::InhibitMousePress)
				{
					case sf::Event::MouseButtonPressed:
					{
						switch (event.mouseButton.button)
						{
							if (*m_CurrentState == GAME_STATE::TITLE)
							{
								case sf::Mouse::Left:
								{
									if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonPlay"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_PLAY;
									}

									if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonQuit"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_QUIT;
									}
								}
								break;
							}
						}
					}
					break;
				}

				if (!Input::InhibitMouseRelease)
				{
					case sf::Event::MouseButtonReleased:
					{
						//
					}
					break;
				}
			}
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
	static Sound*			soundOk				= &m_Sounds->get("SoundOk");
	static RectangleShape*	background			= &m_RectangleShapes->get("Background");
	static RectangleShape*	buttonPlay			= &m_RectangleShapes->get("ButtonPlay");
	static RectangleShape*	buttonGameMode		= &m_RectangleShapes->get("ButtonGameMode");
	static RectangleShape*	buttonScreenMode	= &m_RectangleShapes->get("ButtonScreenMode");
	static RectangleShape*	buttonResolution	= &m_RectangleShapes->get("ButtonResolution");
	static RectangleShape*	buttonQuit			= &m_RectangleShapes->get("ButtonQuit");
	static RectangleShape*	splashScreen		= &m_RectangleShapes->get("SplashScreen");

	// fade ins
	if (m_TitleState == TITLE_STATE::START)
	{
		// fade out splash screen
		if (!splashScreen->isTransparent())
		{
			splashScreen->fadeOut(m_FadeSpeed);
		}

		// fade in background
		else if (!background->isOpaque())
		{
			background->fadeIn(m_FadeSpeed);
		}

		// fade in buttons
		else if (buttonPlay->getOpacity() < 100.f)
		{
			buttonPlay->fadeIn(m_FadeSpeed);
			buttonGameMode->fadeIn(m_FadeSpeed);
			buttonScreenMode->fadeIn(m_FadeSpeed);
			buttonResolution->fadeIn(m_FadeSpeed);
			buttonQuit->fadeIn(m_FadeSpeed);

			if (buttonPlay->getOpacity() >= 100.f)
			{
				buttonPlay->setOpacity(100.f);
			}
		}
	}

	// fade outs and state switch to GAME_STATE::PLAY
	else if (m_TitleState == TITLE_STATE::CHOICE_PLAY)
	{
		// highlight for clicking button or pressing hotkey for 'Play'
		if (buttonPlay->getFillColor().r < 35)
		{
			soundOk->play();
			buttonPlay->setFillColor(sf::Color(35, 35, 35, 100));
		}

		// fade out buttons
		else if (!buttonPlay->isTransparent())
		{
			buttonPlay->fadeOut(m_FadeSpeed);
			buttonGameMode->fadeOut(m_FadeSpeed);
			buttonScreenMode->fadeOut(m_FadeSpeed);
			buttonResolution->fadeOut(m_FadeSpeed);
			buttonQuit->fadeOut(m_FadeSpeed);
		}

		// fade out background
		else if (!background->isTransparent())
		{
			background->fadeOut(m_FadeSpeed);
		}

		// fade out splash screen
		else if (!splashScreen->isOpaque())
		{
			splashScreen->fadeIn(m_FadeSpeed);

			if (splashScreen->isOpaque())
			{
				m_Texts->get("TextTitleID").setRenderEnabled(			false	);
				m_Texts->get("TextTitleVersion").setRenderEnabled(		false	);
				m_Texts->get("TextTitlePlay").setRenderEnabled(			false	);
				m_Texts->get("TextTitleGameMode").setRenderEnabled(		false	);
				m_Texts->get("TextTitleScreenMode").setRenderEnabled(	false	);
				m_Texts->get("TextTitleResolution").setRenderEnabled(	false	);
				m_Texts->get("TextTitleQuit").setRenderEnabled(			false	);
				m_Texts->get("TextTitleDetails").setRenderEnabled(		false	);
				m_Texts->get("TextMessage").setRenderEnabled(			true	);
				m_Texts->get("TextPlayerLeftID").setRenderEnabled(		true	);
				m_Texts->get("TextPlayerLeftScore").setRenderEnabled(	true	);
				m_Texts->get("TextPlayerLeftRank").setRenderEnabled(	true	);
				m_Texts->get("TextPlayerRightID").setRenderEnabled(		true	);
				m_Texts->get("TextPlayerRightScore").setRenderEnabled(	true	);
				m_Texts->get("TextPlayerRightRank").setRenderEnabled(	true	);

				buttonPlay->setFillColor(sf::Color(0, 0, 0, 0));

				m_TitleState = TITLE_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::PLAY;
			}
		}
	}

	// fade outs and state switch to GAME_STATE::Exit
	else if (m_TitleState == TITLE_STATE::CHOICE_QUIT)
	{
		// highlight for clicking button or pressing hotkey for 'Quit'
		if (buttonQuit->getFillColor().r < 35)
		{
			soundOk->play();
			buttonQuit->setFillColor(sf::Color(35, 35, 35, 100));
		}

		// fade out buttons
		else if (!buttonPlay->isTransparent())
		{
			buttonPlay->fadeOut(m_FadeSpeed);
			buttonGameMode->fadeOut(m_FadeSpeed);
			buttonScreenMode->fadeOut(m_FadeSpeed);
			buttonResolution->fadeOut(m_FadeSpeed);
			buttonQuit->fadeOut(m_FadeSpeed);
		}

		// fade out background
		else if (!background->isTransparent())
		{
			background->fadeOut(m_FadeSpeed);
		}

		// fade out splash screen
		else if (!splashScreen->isOpaque())
		{
			splashScreen->fadeIn(m_FadeSpeed);

			if (splashScreen->isOpaque())
			{
				buttonQuit->setFillColor(sf::Color(0, 0, 0, 0));

				m_TitleState = TITLE_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::EXIT;
			}
		}
	}
}

void Update::updateLoad()
{
	// TO DO
}

void Update::updatePlay()
{
	static Sound*			soundOk			= &m_Sounds->get("SoundOk");
	static RectangleShape*	background		= &m_RectangleShapes->get("Background");
	static RectangleShape*	splashScreen	= &m_RectangleShapes->get("SplashScreen");
	static RectangleShape*	playerLeft		= &m_RectangleShapes->get("PlayerLeft");
	static RectangleShape*	playerRight		= &m_RectangleShapes->get("PlayerRight");
	static RectangleShape*	pongBall		= &m_RectangleShapes->get("PongBall");
	
	if (m_PlayState == PLAY_STATE::START)
	{
		// fade out splash screen
		if (!splashScreen->isTransparent())
		{
			splashScreen->fadeOut(m_FadeSpeed);
		}
	
		// fade in background
		else if (!background->isOpaque())
		{
			background->fadeIn(m_FadeSpeed);
		}
	
		// fade in buttons
		else if (!playerLeft->isOpaque())
		{
			playerLeft->fadeIn(m_FadeSpeed);
			playerRight->fadeIn(m_FadeSpeed);
			pongBall->fadeIn(m_FadeSpeed);
	
			if (playerLeft->isOpaque())
			{
				m_PlayState = PLAY_STATE::PLAYING;
			}
		}
	}

	// fade outs and state switch to GAME_STATE::Exit
	else if (m_PlayState == PLAY_STATE::QUIT)
	{

		if (background->isOpaque())
		{
			soundOk->play();
			background->setOpacity(254);
		}

		// fade out entities
		if (!playerLeft->isTransparent())
		{
			playerLeft->fadeOut(m_FadeSpeed);
			playerRight->fadeOut(m_FadeSpeed);
			pongBall->fadeOut(m_FadeSpeed);
		}

		// fade out background
		else if (!background->isTransparent())
		{
			background->fadeOut(m_FadeSpeed);
		}

		// fade out splash screen
		else if (!splashScreen->isOpaque())
		{
			splashScreen->fadeIn(m_FadeSpeed);

			if (splashScreen->isOpaque())
			{
				m_Texts->get("TextTitleID").setRenderEnabled(			true	);
				m_Texts->get("TextTitleVersion").setRenderEnabled(		true	);
				m_Texts->get("TextTitlePlay").setRenderEnabled(			true	);
				m_Texts->get("TextTitleGameMode").setRenderEnabled(		true	);
				m_Texts->get("TextTitleScreenMode").setRenderEnabled(	true	);
				m_Texts->get("TextTitleResolution").setRenderEnabled(	true	);
				m_Texts->get("TextTitleQuit").setRenderEnabled(			true	);
				m_Texts->get("TextTitleDetails").setRenderEnabled(		true	);

				m_Texts->get("TextMessage").setRenderEnabled(			false	);
				m_Texts->get("TextPlayerLeftID").setRenderEnabled(		false	);
				m_Texts->get("TextPlayerLeftScore").setRenderEnabled(	false	);
				m_Texts->get("TextPlayerLeftRank").setRenderEnabled(	false	);
				m_Texts->get("TextPlayerRightID").setRenderEnabled(		false	);
				m_Texts->get("TextPlayerRightScore").setRenderEnabled(	false	);
				m_Texts->get("TextPlayerRightRank").setRenderEnabled(	false	);

				m_PlayState = PLAY_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::TITLE;
			}
		}
	}
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
	m_RenderWindow->close();
}
