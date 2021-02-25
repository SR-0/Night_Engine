#include "Engine.h"





// sfml includes
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

// core static declaration
RenderWindow*	Engine::s_RenderWindow;
unsigned int	Engine::s_RenderLayerCount;
DeltaTime		Engine::s_DeltaTime;
sf::Vector2f	Engine::s_Resolution;
sf::Vector2f	Engine::s_AspectRatio;
sf::Vector2f	Engine::s_Scale;
GAME_STATE		Engine::s_PreviousState;
GAME_STATE		Engine::s_CurrentState;
GAME_STATE		Engine::s_NextState;

// object manager static declaration
ObjectManager<SoundBuffer>		Engine::s_SoundBuffers;
ObjectManager<Font>				Engine::s_Fonts;
ObjectManager<Texture>			Engine::s_Textures;
ObjectManager<Sound>			Engine::s_Sounds;
ObjectManager<Music>			Engine::s_Music;
ObjectManager<Text>				Engine::s_Texts;
ObjectManager<RectangleShape>	Engine::s_RectangleShapes;

// bool checks static declaration
bool Engine::s_SetupInitiated;
bool Engine::s_UpdateInitiated;
bool Engine::s_RenderInitiated;
bool Engine::s_DestroyInitiated;





#pragma region CORE: CREATE - SETUP - UPDATE - RENDER - DESTROY

void Engine::CreateCore(EngineCallable& callable, sf::VideoMode videoMode, sf::String title, bool isFullScreen, sf::ContextSettings contextSettings)
{
	s_RenderWindow		= new RenderWindow(videoMode, title, (isFullScreen ? sf::Style::Fullscreen : sf::Style::None), contextSettings);
	
	s_SetupInitiated	= false;
	s_UpdateInitiated	= false;
	s_RenderInitiated	= false;
	s_DestroyInitiated	= false;

	callable.attachRenderWindow(		*s_RenderWindow		);
	callable.attachRenderLayerCount(	s_RenderLayerCount	);
	callable.attachDeltaTime(			s_DeltaTime			);
	callable.attachResolution(			s_Resolution		);
	callable.attachAspectRatio(			s_AspectRatio		);
	callable.attachScale(				s_Scale				);
	callable.attachPreviousState(		s_PreviousState		);
	callable.attachCurrentState(		s_CurrentState		);
	callable.attachNextState(			s_NextState			);

	callable.attachSoundBuffers(	s_SoundBuffers		);
	callable.attachFonts(			s_Fonts				);
	callable.attachTextures(		s_Textures			);
	callable.attachSounds(			s_Sounds			);
	callable.attachMusic(			s_Music				);
	callable.attachTexts(			s_Texts				);
	callable.attachRectangleShapes(	s_RectangleShapes	);

	callable.execute();
}

void Engine::SetupCore(EngineCallable& callable)
{
	if (!s_SetupInitiated)
	{
		callable.attachRenderWindow(		*s_RenderWindow		);
		callable.attachRenderLayerCount(	s_RenderLayerCount	);
		callable.attachDeltaTime(			s_DeltaTime			);
		callable.attachResolution(			s_Resolution		);
		callable.attachAspectRatio(			s_AspectRatio		);
		callable.attachScale(				s_Scale				);
		callable.attachPreviousState(		s_PreviousState		);
		callable.attachCurrentState(		s_CurrentState		);
		callable.attachNextState(			s_NextState			);

		callable.attachSoundBuffers(	s_SoundBuffers		);
		callable.attachFonts(			s_Fonts				);
		callable.attachTextures(		s_Textures			);
		callable.attachSounds(			s_Sounds			);
		callable.attachMusic(			s_Music				);
		callable.attachTexts(			s_Texts				);
		callable.attachRectangleShapes(	s_RectangleShapes	);

		s_SetupInitiated = true;

		SetupCore(callable);
	}
	else
	{
		callable.execute();
	}
}

void Engine::UpdateCore(EngineCallable& callable)
{
	if (!s_UpdateInitiated)
	{
		callable.attachRenderWindow(		*s_RenderWindow		);
		callable.attachRenderLayerCount(	s_RenderLayerCount	);
		callable.attachDeltaTime(			s_DeltaTime			);
		callable.attachResolution(			s_Resolution		);
		callable.attachAspectRatio(			s_AspectRatio		);
		callable.attachScale(				s_Scale				);
		callable.attachPreviousState(		s_PreviousState		);
		callable.attachCurrentState(		s_CurrentState		);
		callable.attachNextState(			s_NextState			);


		callable.attachSoundBuffers(	s_SoundBuffers		);
		callable.attachFonts(			s_Fonts				);
		callable.attachTextures(		s_Textures			);
		callable.attachSounds(			s_Sounds			);
		callable.attachMusic(			s_Music				);
		callable.attachTexts(			s_Texts				);
		callable.attachRectangleShapes(	s_RectangleShapes	);

		s_UpdateInitiated = true;

		UpdateCore(callable);
	}
	else
	{
		callable.execute();
	}
}

void Engine::RenderCore(EngineCallable& callable)
{
	if (!s_RenderInitiated)
	{
		callable.attachRenderWindow(		*s_RenderWindow		);
		callable.attachRenderLayerCount(	s_RenderLayerCount	);
		callable.attachDeltaTime(			s_DeltaTime			);
		callable.attachResolution(			s_Resolution		);
		callable.attachAspectRatio(			s_AspectRatio		);
		callable.attachScale(				s_Scale				);
		callable.attachPreviousState(		s_PreviousState		);
		callable.attachCurrentState(		s_CurrentState		);
		callable.attachNextState(			s_NextState			);

		callable.attachSoundBuffers(	s_SoundBuffers		);
		callable.attachFonts(			s_Fonts				);
		callable.attachTextures(		s_Textures			);
		callable.attachSounds(			s_Sounds			);
		callable.attachMusic(			s_Music				);
		callable.attachTexts(			s_Texts				);
		callable.attachRectangleShapes(	s_RectangleShapes	);

		s_RenderInitiated = true;

		RenderCore(callable);
	}
	else
	{
		callable.execute();
	}
}

void Engine::DestroyCore(EngineCallable& callable)
{
	if (!s_DestroyInitiated)
	{
		callable.attachRenderWindow(		*s_RenderWindow		);
		callable.attachRenderLayerCount(	s_RenderLayerCount	);
		callable.attachDeltaTime(			s_DeltaTime			);
		callable.attachResolution(			s_Resolution		);
		callable.attachAspectRatio(			s_AspectRatio		);
		callable.attachScale(				s_Scale				);
		callable.attachPreviousState(		s_PreviousState		);
		callable.attachCurrentState(		s_CurrentState		);
		callable.attachNextState(			s_NextState			);

		callable.attachSoundBuffers(	s_SoundBuffers		);
		callable.attachFonts(			s_Fonts				);
		callable.attachTextures(		s_Textures			);
		callable.attachSounds(			s_Sounds			);
		callable.attachMusic(			s_Music				);
		callable.attachTexts(			s_Texts				);
		callable.attachRectangleShapes(	s_RectangleShapes	);

		s_DestroyInitiated = true;
		
		DestroyCore(callable);
	}
	else
	{
		callable.execute();

		delete s_RenderWindow;
	}
}

#pragma endregion CREATE - SETUP - UPDATE - RENDER - DESTROY





#pragma region RETURN FUNCTIONS

bool Engine::IsRunning()
{
	return (s_RenderWindow->isOpen());
}

#pragma endregion RETURN FUNCTIONS