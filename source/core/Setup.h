#pragma once

#include "EngineCallable.h"

class Setup : public EngineCallable
{
public:

	virtual void execute();

public:

	virtual void setupAll();

public:

	virtual void setupCore();
	virtual void setupSoundBuffers();
	virtual void setupFonts();
	virtual void setupTextures();
	virtual void setupSounds();
	virtual void setupMusic();
	virtual void setupTexts();
	virtual void setupRectangleShapes();

};
