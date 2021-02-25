#pragma once

#include "EngineCallable.h"

class Create : public EngineCallable
{
public:

	virtual void execute();
	
public:
	
	virtual void createAll();

public:

	virtual void createCore();
	virtual void createSoundBuffers();
	virtual void createFonts();
	virtual void createTextures();
	virtual void createSounds();
	virtual void createMusic();
	virtual void createTexts();
	virtual void createRectangleShapes();

};
