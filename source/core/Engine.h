#pragma once

// derived callable includes
#include "Create.h"
#include "Setup.h"
#include "Update.h"
#include "Render.h"
#include "Destroy.h"

class Engine
{
private:

	Engine() = default;

	/*  // simple, if not barbaric design flow for entire engine:

                                                 -------------		
                                         / -- -> |   Update  | -- -> \
                                         ^       -------------       |
    ------------       -----------       |                           |       -------------
    |  Create  | -- -> |  Setup  | -- -> |           (LOOP)          | -- -> |  Destroy  |
    ------------       -----------       |                           |       -------------
                                         |       -------------       v
                                         \ <- -- |   Render  | <- -- /
                                                 -------------

	*/ // make dirved engine callables (or an array of derived engine callables in the future) for each stage

public:

	// Core functions that handle *all* create, setup, update, render, and destroy flows
	static void CreateCore(EngineCallable& callable, sf::VideoMode videoMode, sf::String title, bool isFullScreen, sf::ContextSettings contextSettings);
	static void SetupCore(EngineCallable& callable);
	static void UpdateCore(EngineCallable& callable);
	static void RenderCore(EngineCallable& callable);
	static void DestroyCore(EngineCallable& callable);

private:

	// attach all required/critical global variable/object references (required for any derived callable)
	static void InitiateAttachments(EngineCallable& callable);

public:

	// return true if window is open for now
	static bool IsRunning();

public:

	// global engine variables/objects that need to be attached to 'engine callables'
	static RenderWindow*	s_RenderWindow;
	static unsigned int		s_RenderLayerCount;
	static DeltaTime		s_DeltaTime;
	static sf::Vector2f		s_Resolution;
	static sf::Vector2f		s_AspectRatio;
	static sf::Vector2f		s_Scale;
	static GAME_STATE		s_PreviousState;
	static GAME_STATE		s_CurrentState;

	
public:

	// global engine object managers that need to be attached to 'engine callables'
	static ObjectManager<SoundBuffer>		s_SoundBuffers;
	static ObjectManager<Font>				s_Fonts;
	static ObjectManager<Texture>			s_Textures;
	static ObjectManager<Sound>				s_Sounds;
	static ObjectManager<Music*>			s_Music;
	static ObjectManager<Text>				s_Texts;
	static ObjectManager<RectangleShape>	s_RectangleShapes;

public:

	// initial start-up checks only
	static bool	s_SetupInitiated;
	static bool	s_UpdateInitiated;
	static bool	s_RenderInitiated;
	static bool	s_DestroyInitiated;

};

