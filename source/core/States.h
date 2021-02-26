#pragma once

enum class GAME_STATE
{
	NONE,
	TITLE,
	LOAD,
	PLAY,
	PAUSE,
	SAVE,
	EXIT
};

enum class TITLE_STATE
{
	START,

	CHOICE_PLAY,
	CHOICE_GAME_MODE,
	CHOICE_SCREEN_MODE,
	CHOICE_RESOLUTION,
	CHOICE_QUIT,
};

enum class LOAD_STATE
{
	START,
};

enum class PLAY_STATE
{
	START,
	PLAYING,
	QUIT
};

enum class PAUSE_STATE
{
	START
};

enum class SAVE_STATE
{
	START
};

enum class EXIT_STATE
{
	START
};