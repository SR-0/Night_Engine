#pragma once

#include "EngineCallable.h"

class Destroy : public EngineCallable
{
public:

	void execute();

public:

	void destroyAll();

public:

	void destroyCore();
	void destroySoundBuffers();
	void destroyFonts();
	void destroyTextures();
	void destroySounds();
	void destroyMusic();
	void destroyTexts();
	void destroyRectangleShapes();

};

