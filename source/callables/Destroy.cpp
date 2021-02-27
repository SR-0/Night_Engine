#include "Destroy.h"

void Destroy::execute()
{
	destroyAll();
}

void Destroy::destroyAll()
{
	destroyCore();
	destroySoundBuffers();
	destroyFonts();
	destroyTextures();
	destroySounds();
	destroyMusic();
	destroyTexts();
	destroyRectangleShapes();
}

void Destroy::destroyCore()
{
}

void Destroy::destroySoundBuffers()
{
	m_SoundBuffers->destroyAll();
}

void Destroy::destroyFonts()
{
	m_Fonts->destroyAll();
}

void Destroy::destroyTextures()
{
	m_Textures->destroyAll();
}

void Destroy::destroySounds()
{
	m_Sounds->destroyAll();
}

void Destroy::destroyMusic()
{
	m_Music->destroyAll(); // <- what's is going on with this, should work just as well as the others but gives me an error
}

void Destroy::destroyTexts()
{
	m_Texts->destroyAll();
}

void Destroy::destroyRectangleShapes()
{
	m_RectangleShapes->destroyAll();
}