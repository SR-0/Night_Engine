#pragma once

#include "EngineCallable.h"

class Destroy : public EngineCallable
{
public:

	virtual void execute();

public:

	virtual void destroyAll();

public:

	virtual void destroyCore();
	virtual void destroySoundBuffers();
	virtual void destroyFonts();
	virtual void destroyTextures();
	virtual void destroySounds();
	virtual void destroyMusic();
	virtual void destroyTexts();
	virtual void destroyRectangleShapes();

};

