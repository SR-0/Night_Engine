#pragma once

#include "EngineCallable.h"

class Update : public EngineCallable
{
public:

	virtual void execute();

public:

	virtual void updateAll();
	
public:

	virtual void updateDelta();
	virtual void updateEvent();
	virtual void updateState();

public:

	virtual void updateTitle();
	virtual void updateLoad();
	virtual void updatePlay();
	virtual void updatePause();
	virtual void updateSave();
	virtual void updateExit();

private:

	bool m_InhibitPressed	= false;
	bool m_InhibitReleased	= false;

public:

	const float fadeSpeed = 5.f;

};