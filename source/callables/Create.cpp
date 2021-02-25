#include "Create.h"

void Create::execute()
{
	createAll();
}

void Create::createAll()
{
	createSoundBuffers();
	createFonts();
	createTextures();
	createSounds();
	createMusic();
	createTexts();
	createRectangleShapes();
}


void Create::createCore()
{
}

void Create::createSoundBuffers()
{
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferHit");
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferScore");
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferWin");
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferLose");
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferOK");
	m_SoundBuffers->create(SoundBuffer(), "SoundBufferCancel");

}

void Create::createFonts()
{
	m_Fonts->create(Font(), "FontMain");
}

void Create::createTextures()
{
	m_Textures->create(Texture(), "TextureBackground");
	m_Textures->create(Texture(), "TexturePongBall");
	m_Textures->create(Texture(), "TexturePlayerLeft");
	m_Textures->create(Texture(), "TexturePlayerRight");
}

void Create::createSounds()
{
	m_Sounds->create(Sound(), "SoundHit");
	m_Sounds->create(Sound(), "SoundScore");
	m_Sounds->create(Sound(), "SoundWin");
	m_Sounds->create(Sound(), "SoundLose");
	m_Sounds->create(Sound(), "SoundOK");
	m_Sounds->create(Sound(), "SoundCancel");
}

void Create::createMusic()
{
	//m_Music->create(Music(), "MusicAmbient"); 
}

void Create::createTexts()
{
	m_Texts->create(Text(), "TextTitleID");
	m_Texts->create(Text(), "TextTitleVersion");
	m_Texts->create(Text(), "TextTitlePlay");
	m_Texts->create(Text(), "TextTitleGameMode");
	m_Texts->create(Text(), "TextTitleScreenMode");
	m_Texts->create(Text(), "TextTitleResolution");
	m_Texts->create(Text(), "TextTitleQuit");
	m_Texts->create(Text(), "TextTitleDetails");
	m_Texts->create(Text(), "TextOK");
	m_Texts->create(Text(), "TextCancel");
	m_Texts->create(Text(), "TextClose");
	m_Texts->create(Text(), "TextMessage");
	m_Texts->create(Text(), "TextPlayerLeftID");
	m_Texts->create(Text(), "TextPlayerLeftScore");
	m_Texts->create(Text(), "TextPlayerLeftRank");
	m_Texts->create(Text(), "TextPlayerRightID");
	m_Texts->create(Text(), "TextPlayerRightScore");
	m_Texts->create(Text(), "TextPlayerRightRank");
}

void Create::createRectangleShapes()
{
	m_RectangleShapes->create(RectangleShape(), "Background");
	m_RectangleShapes->create(RectangleShape(), "ButtonPlay");
	m_RectangleShapes->create(RectangleShape(), "ButtonGameMode");
	m_RectangleShapes->create(RectangleShape(), "ButtonScreenMode");
	m_RectangleShapes->create(RectangleShape(), "ButtonResolution");
	m_RectangleShapes->create(RectangleShape(), "ButtonOk");
	m_RectangleShapes->create(RectangleShape(), "ButtonApply");
	m_RectangleShapes->create(RectangleShape(), "ButtonCancel");
	m_RectangleShapes->create(RectangleShape(), "ButtonResume");
	m_RectangleShapes->create(RectangleShape(), "ButtonQuit");
	m_RectangleShapes->create(RectangleShape(), "MessageBanner");
	m_RectangleShapes->create(RectangleShape(), "SplashScreen");
	m_RectangleShapes->create(RectangleShape(), "PlayerLeft");
	m_RectangleShapes->create(RectangleShape(), "PlayerRight");
	m_RectangleShapes->create(RectangleShape(), "PongBall");
}
