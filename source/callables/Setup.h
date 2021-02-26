#pragma once

#include "EngineCallable.h"

class Setup : public EngineCallable
{
public:

	void execute();

public:

	void setupAll();

public:

	void setupCore();
	void setupSoundBuffers();
	void setupFonts();
	void setupTextures();
	void setupSounds();
	void setupMusic();
	void setupTexts();
	void setupRectangleShapes();

};
