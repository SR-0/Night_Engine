#pragma once

#include "EngineCallable.h"

class Create : public EngineCallable
{
public:

	void execute();
	
public:
	
	void createAll();

public:

	void createCore();
	void createSoundBuffers();
	void createFonts();
	void createTextures();
	void createSounds();
	void createMusic();
	void createTexts();
	void createRectangleShapes();

};