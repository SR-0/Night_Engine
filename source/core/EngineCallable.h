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

	virtual void execute() = 0;

public:


	RenderWindow*	m_RenderWindow		= nullptr;
	unsigned int*	m_RenderLayerCount	= nullptr;
	DeltaTime*		m_DeltaTime			= nullptr;
	sf::Vector2f*	m_Resolution		= nullptr;
	sf::Vector2f*	m_AspectRatio		= nullptr;
	sf::Vector2f*	m_Scale				= nullptr;
	GAME_STATE*		m_PreviousState		= nullptr;
	GAME_STATE*		m_CurrentState		= nullptr;

public:

	ObjectManager<SoundBuffer>*		m_SoundBuffers		= nullptr;
	ObjectManager<Font>*			m_Fonts				= nullptr;
	ObjectManager<Texture>*			m_Textures			= nullptr;
	ObjectManager<Sound>*			m_Sounds			= nullptr;
	ObjectManager<Music*>*			m_Music				= nullptr;
	ObjectManager<Text>*			m_Texts				= nullptr;
	ObjectManager<RectangleShape>*	m_RectangleShapes	= nullptr;

};