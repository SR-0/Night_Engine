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
							case sf::Mouse::Left:
							{
								if (*m_CurrentState == GAME_STATE::TITLE)
								{
									if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonPlay"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_PLAY;
									}

									else if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonScreenMode"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_SCREEN_MODE;
									}

									else if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonResolution"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_RESOLUTION;
									}

									else if (Input::leftClickPressedOver(m_RectangleShapes->get("ButtonQuit"), *m_RenderWindow))
									{
										m_TitleState = TITLE_STATE::CHOICE_QUIT;
									}
								}
							}
							break;

							case sf::Mouse::Right:
							{
								// TO DO
							}
							break;
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

		case GAME_STATE::RESET:
		{
			updateReset();
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

	if (m_TitleState == TITLE_STATE::START)
	{
		// music start
		if (m_Music->get("MusicAmbient")->getStatus() == sf::Music::Status::Stopped)
		{
			m_Music->get("MusicAmbient")->play();
		}

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

	else if (m_TitleState == TITLE_STATE::CHOICE_PLAY)
	{
		// highlight for clicking button or pressing hotkey for 'Play'
		if (buttonPlay->getFillColor().r < 50)
		{
			soundOk->play();
			buttonPlay->setFillColor(sf::Color(50, 50, 50, 100));
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

				buttonPlay->setFillColor(sf::Color(0, 0, 0, 0));

				m_TitleState = TITLE_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::PLAY;
			}
		}
	}

	else if (m_TitleState == TITLE_STATE::CHOICE_SCREEN_MODE)
	{
		// highlight for clicking button or pressing hotkey for 'ScreenMOde'
		if (buttonScreenMode->getFillColor().r < 50)
		{
			soundOk->play();
			buttonScreenMode->setFillColor(sf::Color(50, 50, 50, 100));
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

				if (*m_Style == sf::Style::Fullscreen)
				{
					*m_Style = sf::Style::None;
					m_Texts->get("TextTitleScreenMode").setString("Borderless");
				}
				else if (*m_Style == sf::Style::None)
				{
					*m_Style = sf::Style::Fullscreen;
					m_Texts->get("TextTitleScreenMode").setString("Fullscreen");

				}

				m_TitleState = TITLE_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::RESET;
			}
		}
	}

	// fade outs and state switch to GAME_STATE::Exit
	else if (m_TitleState == TITLE_STATE::CHOICE_RESOLUTION)
	{
		// highlight for clicking button or pressing hotkey for 'Resolution'
		if (buttonResolution->getFillColor().r < 50)
		{
			soundOk->play();
			buttonResolution->setFillColor(sf::Color(50, 50, 50, 100));
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

				if (*m_Resolution == sf::Vector2f(1280, 720))
				{
					*m_Resolution = sf::Vector2f(1600, 900);
				}
				else if (*m_Resolution == sf::Vector2f(1600, 900))
				{
					*m_Resolution = sf::Vector2f(1920, 1080);
				}
				else if (*m_Resolution == sf::Vector2f(1920, 1080))
				{
					*m_Resolution = sf::Vector2f(2560, 1440);
				}
				else if (*m_Resolution == sf::Vector2f(2560, 1440))
				{
					*m_Resolution = sf::Vector2f(3840, 2160);
				}
				else if (*m_Resolution == sf::Vector2f(3840, 2160))
				{
					*m_Resolution = sf::Vector2f(5120, 2880);
				}
				else if (*m_Resolution == sf::Vector2f(5120, 2880))
				{
					*m_Resolution = sf::Vector2f(7680, 4320);
				}
				else if (*m_Resolution == sf::Vector2f(7680, 4320))
				{
					*m_Resolution = sf::Vector2f(3040, 1440);
				}
				else if (*m_Resolution == sf::Vector2f(3040, 1440))
				{
					*m_Resolution = sf::Vector2f(1280, 720);
				}

				m_TitleState = TITLE_STATE::START;
				*m_PreviousState = *m_CurrentState;
				*m_CurrentState = GAME_STATE::RESET;
			}
		}
	}

	// fade outs and state switch to GAME_STATE::Exit
	else if (m_TitleState == TITLE_STATE::CHOICE_QUIT)
	{
		// highlight for clicking button or pressing hotkey for 'Quit'
		if (buttonQuit->getFillColor().r < 50)
		{
			soundOk->play();
			buttonQuit->setFillColor(sf::Color(50, 50, 50, 100));
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
				buttonScreenMode->setFillColor(sf::Color(0, 0, 0, 0));

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
	static Sound*			soundOk					= &m_Sounds->get("SoundOk");
	static Text*			textPlayerLeftID		= &m_Texts->get("TextPlayerLeftID");
	static Text*			textPlayerLeftScore		= &m_Texts->get("TextPlayerLeftScore");
	static Text*			textPlayerLeftRank		= &m_Texts->get("TextPlayerLeftRank");
	static Text*			textPlayerRightID		= &m_Texts->get("TextPlayerRightID");
	static Text*			textPlayerRightScore	= &m_Texts->get("TextPlayerRightScore");
	static Text*			textPlayerRightRank		= &m_Texts->get("TextPlayerRightRank");
	static Text*			textMessage				= &m_Texts->get("TextMessage");
	static RectangleShape*	background				= &m_RectangleShapes->get("Background");
	static RectangleShape*	splashScreen			= &m_RectangleShapes->get("SplashScreen");
	static RectangleShape*	playerLeft				= &m_RectangleShapes->get("PlayerLeft");
	static RectangleShape*	playerRight				= &m_RectangleShapes->get("PlayerRight");
	static RectangleShape*	pongBall				= &m_RectangleShapes->get("PongBall");
	
	if (m_PlayState == PLAY_STATE::START)
	{
		// fade out splash screen
		if (!splashScreen->isTransparent())
		{
			textPlayerLeftID->setRenderEnabled(			true	);
			textPlayerLeftScore->setRenderEnabled(		true	);
			textPlayerLeftRank->setRenderEnabled(		true	);
			textPlayerRightID->setRenderEnabled(		true	);
			textPlayerRightScore->setRenderEnabled(		true	);
			textPlayerRightRank->setRenderEnabled(		true	);

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
				textMessage->setRenderEnabled(true);
				textMessage->setRenderLayer(3);
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
				m_DeltaTime->setTimerEnd(m_DeltaTime->getElapsed() + sf::seconds(1));
				std::cout << (std::string)textMessage->getString() << std::endl;
			}
		}

		else if (m_Texts->get("TextMessage").getString() == "Game Starting In... 3")
		{
			if (m_DeltaTime->getTimerStart().asSeconds() >= m_DeltaTime->getTimerEnd().asSeconds())
			{
				textMessage->setString("Game Starting In... 2");
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
				m_DeltaTime->setTimerEnd(m_DeltaTime->getTimerStart() + sf::Time(sf::seconds(1)));
			}
			else
			{
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
			}
		}
		else if (m_Texts->get("TextMessage").getString() == "Game Starting In... 2")
		{
			if (m_DeltaTime->getTimerStart().asSeconds() >= m_DeltaTime->getTimerEnd().asSeconds())
			{
				textMessage->setString("Game Starting In... 1");
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
				m_DeltaTime->setTimerEnd(m_DeltaTime->getTimerStart() + sf::Time(sf::seconds(1)));
			}
			else
			{
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
			}
		}
		else if (m_Texts->get("TextMessage").getString() ==	"Game Starting In... 1")
		{
			if (m_DeltaTime->getTimerStart().asSeconds() >= m_DeltaTime->getTimerEnd().asSeconds())
			{
				textMessage->setString("           Go!");
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
				m_DeltaTime->setTimerEnd(m_DeltaTime->getTimerStart() + sf::Time(sf::seconds(1)));;
			}
			else
			{
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
			}
		}
		else if (m_Texts->get("TextMessage").getString() ==	"           Go!")
		{
			if (m_DeltaTime->getTimerStart().asSeconds() >= m_DeltaTime->getTimerEnd().asSeconds())
			{
				textMessage->setString("");
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
				m_DeltaTime->setTimerEnd(m_DeltaTime->getTimerStart() + sf::Time(sf::seconds(1)));
			}
			else
			{
				m_DeltaTime->setTimerStart(m_DeltaTime->getElapsed());
			}
		}
	}


	else if (m_PlayState == PLAY_STATE::PLAYING)
	{

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

void Update::updateReset()
{
	const auto resolutionStringX = std::to_string((int)m_Resolution->x);
	const auto resolutionStringY = std::to_string((int)m_Resolution->y);

	m_Texts->get("TextTitleResolution").setString(resolutionStringX + "x" + resolutionStringY);

	m_RenderWindow->close();

	delete m_RenderWindow;

	m_RenderWindow = new RenderWindow(sf::VideoMode(m_Resolution->x, m_Resolution->y), *m_Title, *m_Style, *m_ContextSettings);

	*m_PreviousState = *m_CurrentState;
	*m_CurrentState = GAME_STATE::NONE;
}

void Update::updateExit()
{
	m_RenderWindow->close();
}
