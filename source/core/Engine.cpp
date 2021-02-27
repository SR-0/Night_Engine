#include "Engine.h"

// core static declaration
RenderWindow*		Engine::s_RenderWindow;
sf::VideoMode		Engine::s_VideoMode;
sf::String			Engine::s_Title;
sf::Uint32			Engine::s_Style;
sf::ContextSettings	Engine::s_ContextSettings;
unsigned int		Engine::s_RenderLayerCount;
DeltaTime			Engine::s_DeltaTime;
sf::Vector2f		Engine::s_Resolution;
sf::Vector2f		Engine::s_AspectRatio;
sf::Vector2f		Engine::s_Scale;
GAME_STATE			Engine::s_PreviousState;
GAME_STATE			Engine::s_CurrentState;


// object manager static declaration
ObjectManager<SoundBuffer>		Engine::s_SoundBuffers;
ObjectManager<Font>				Engine::s_Fonts;
ObjectManager<Texture>			Engine::s_Textures;
ObjectManager<Sound>			Engine::s_Sounds;
ObjectManager<Music*>			Engine::s_Music;
ObjectManager<Text>				Engine::s_Texts;
ObjectManager<RectangleShape>	Engine::s_RectangleShapes;

// bool checks static declaration
bool Engine::s_SetupInitiated;
bool Engine::s_UpdateInitiated;
bool Engine::s_RenderInitiated;
bool Engine::s_DestroyInitiated;

// pointers to callables for certain use cases
EngineCallable* Engine::s_Create;
EngineCallable* Engine::s_Setup;
EngineCallable* Engine::s_Update;
EngineCallable* Engine::s_Render;
EngineCallable* Engine::s_Destroy;




#pragma region CORE: CREATE - SETUP - UPDATE - RENDER - DESTROY

void Engine::CreateCore(EngineCallable& callable, sf::VideoMode videoMode, sf::String title, bool isFullScreen, sf::ContextSettings contextSettings)
{
	s_VideoMode			= videoMode;
	s_Title				= title;
	s_Style				= (isFullScreen ? sf::Style::Fullscreen : sf::Style::None);
	s_ContextSettings	= contextSettings;
	s_RenderWindow		= new RenderWindow(s_VideoMode, s_Title, s_Style, s_ContextSettings);
	s_SetupInitiated	= false;
	s_UpdateInitiated	= false;
	s_RenderInitiated	= false;
	s_DestroyInitiated	= false;

	s_Create = &callable;

	InitiateAttachments(callable);

	callable.execute();
}

void Engine::SetupCore(EngineCallable& callable)
{
	if (!s_SetupInitiated)
	{
		s_Setup = &callable;

		InitiateAttachments(callable);

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
		s_Update = &callable;

		InitiateAttachments(callable);

		s_UpdateInitiated = true;

		UpdateCore(callable);
	}
	else if (s_CurrentState == GAME_STATE::NONE)
	{
		SetupCore(*s_Setup);

		s_CurrentState = GAME_STATE::TITLE;
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
		s_Render = &callable;

		InitiateAttachments(callable);

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
		s_Destroy = &callable;

		InitiateAttachments(callable);

		s_RenderWindow->close();

		s_DestroyInitiated = true;
		
		DestroyCore(callable);
	}
	else
	{
		callable.execute();
	}
}

#pragma endregion CREATE - SETUP - UPDATE - RENDER - DESTROY





#pragma region ATTACH CALLABLE REFERENCES

void Engine::InitiateAttachments(EngineCallable& callable)
{
	callable.attachRenderWindow(		*s_RenderWindow		);
	callable.attachVideoMode(			s_VideoMode			);
	callable.attachTitle(				s_Title				);
	callable.attachStyle(				s_Style				);
	callable.attachContextSettings(		s_ContextSettings	);
	callable.attachRenderLayerCount(	s_RenderLayerCount	);
	callable.attachDeltaTime(			s_DeltaTime			);
	callable.attachResolution(			s_Resolution		);
	callable.attachAspectRatio(			s_AspectRatio		);
	callable.attachScale(				s_Scale				);
	callable.attachPreviousState(		s_PreviousState		);
	callable.attachCurrentState(		s_CurrentState		);
	
	callable.attachSoundBuffers(	s_SoundBuffers		);
	callable.attachFonts(			s_Fonts				);
	callable.attachTextures(		s_Textures			);
	callable.attachSounds(			s_Sounds			);
	callable.attachMusic(			s_Music				);
	callable.attachTexts(			s_Texts				);
	callable.attachRectangleShapes(	s_RectangleShapes	);
}

#pragma endregion ATTACH CALLABLE REFERENCES





#pragma region RETURN FUNCTIONS

bool Engine::IsRunning()
{
	return s_RenderWindow->isOpen();
}

#pragma endregion RETURN FUNCTIONS