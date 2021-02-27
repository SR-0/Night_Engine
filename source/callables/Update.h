#pragma once

#include "EngineCallable.h"

class Update : public EngineCallable
{
public:

	void execute();

public:

	void updateAll();
	
public:

	void updateDelta();
	void updateEvent();
	void updateState();

public:

	void updateTitle();
	void updateLoad();
	void updatePlay();
	void updatePause();
	void updateSave();
	void updateReset();
	void updateExit();

public:

public:

	// generic fade in and out speeds for splash, background, buttons, and entities
	const float m_FadeSpeed = 7.f;

	// choice checks
	TITLE_STATE m_TitleState	= TITLE_STATE::START;
	PLAY_STATE	m_PlayState		= PLAY_STATE::START;

};