#pragma once

#include "Common.h"

class EngineCallable
{
public:

	EngineCallable() = default;
	EngineCallable(const EngineCallable& engineCallable) = delete;

public:

	void attachRenderWindow(RenderWindow& renderWindow)
	{
		this->m_RenderWindow = &renderWindow;
	}

	void attachVideoMode(sf::VideoMode& videoMode)
	{
		this->m_VideoMode = &videoMode;
	}

	void attachTitle(sf::String& title)
	{
		this->m_Title = &title;
	}

	void attachStyle(sf::Uint32& style)
	{
		this->m_Style = &style;
	}

	void attachContextSettings(sf::ContextSettings& contextSettings)
	{
		this->m_ContextSettings = &contextSettings;
	}

	void attachRenderLayerCount(unsigned int& renderLayerCount)
	{
		this->m_RenderLayerCount = &renderLayerCount;
	}

	void attachDeltaTime(DeltaTime& deltaTime)
	{
		m_DeltaTime = &deltaTime;
	}

	void attachResolution(sf::Vector2f& resolution)
	{
		this->m_Resolution = &resolution;
	}

	void attachAspectRatio(sf::Vector2f& aspectRatio)
	{
		this->m_AspectRatio = &aspectRatio;
	}

	void attachScale(sf::Vector2f& scale)
	{
		this->m_Scale = &scale;
	}

	void attachPreviousState(GAME_STATE& state)
	{
		this->m_PreviousState = &state;
	}
	
	void attachCurrentState(GAME_STATE& state)
	{
		this->m_CurrentState = &state;
	}

public:

	void attachSoundBuffers(ObjectManager<SoundBuffer>& soundBuffers)
	{
		this->m_SoundBuffers = &soundBuffers;
	}

	void attachFonts(ObjectManager<Font>& fonts)
	{
		this->m_Fonts = &fonts;
	}

	void attachTextures(ObjectManager<Texture>& textures)
	{
		this->m_Textures = &textures;
	}

	void attachSounds(ObjectManager<Sound>& sounds)
	{
		this->m_Sounds = &sounds;
	}

	void attachMusic(ObjectManager<Music*>& music)
	{
		this->m_Music = &music;
	}

	void attachTexts(ObjectManager<Text>& texts)
	{
		this->m_Texts = &texts;
	}

	void attachRectangleShapes(ObjectManager<RectangleShape>& rectangleShapes)
	{
		this->m_RectangleShapes = &rectangleShapes;
	}

public:

	//void detachAll()
	//{
	//	delete m_RenderWindow;		//= nullptr;
	//	delete m_VideoMode;			//= nullptr;
	//	delete m_Title;				//= nullptr;
	//	delete m_Style;				//= nullptr;
	//	delete m_ContextSettings;	//= nullptr;
	//	delete m_RenderLayerCount;	//= nullptr;
	//	delete m_DeltaTime;			//= nullptr;
	//	delete m_Resolution;		//= nullptr;
	//	delete m_AspectRatio;		//= nullptr;
	//	delete m_Scale;				//= nullptr;
	//	delete m_PreviousState;		//= nullptr;
	//	delete m_CurrentState;		//= nullptr;
	//						
	//	delete m_SoundBuffers;		//= nullptr;
	//	delete m_Fonts;				//= nullptr;
	//	delete m_Textures;			//= nullptr;
	//	delete m_Sounds;			//= nullptr;
	//	delete m_Music;				//= nullptr;
	//	delete m_Texts;				//= nullptr;
	//	delete m_RectangleShapes;	//= nullptr;
	//}

public:

	virtual void execute() = 0;

public:

	RenderWindow*			m_RenderWindow		= nullptr;
	sf::VideoMode*			m_VideoMode			= nullptr;
	sf::String*				m_Title				= nullptr;
	sf::Uint32*				m_Style				= nullptr;
	sf::ContextSettings*	m_ContextSettings	= nullptr;
	unsigned int*			m_RenderLayerCount	= nullptr;
	DeltaTime*				m_DeltaTime			= nullptr;
	sf::Vector2f*			m_Resolution		= nullptr;
	sf::Vector2f*			m_AspectRatio		= nullptr;
	sf::Vector2f*			m_Scale				= nullptr;
	GAME_STATE*				m_PreviousState		= nullptr;
	GAME_STATE*				m_CurrentState		= nullptr;

public:

	ObjectManager<SoundBuffer>*		m_SoundBuffers		= nullptr;
	ObjectManager<Font>*			m_Fonts				= nullptr;
	ObjectManager<Texture>*			m_Textures			= nullptr;
	ObjectManager<Sound>*			m_Sounds			= nullptr;
	ObjectManager<Music*>*			m_Music				= nullptr;
	ObjectManager<Text>*			m_Texts				= nullptr;
	ObjectManager<RectangleShape>*	m_RectangleShapes	= nullptr;

};