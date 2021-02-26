#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Input : public sf::Keyboard, public sf::Mouse
{
private:

	Input() : sf::Keyboard(), sf::Mouse() {};

public:

	static bool leftClickPressedOver(sf::RectangleShape& rectangleShape, sf::RenderWindow& window);

public:

	static bool InhibitKeyboard;
	static bool InhibitKeyboardPress;
	static bool InhibitKeyboardRelease;

public:

	static bool InhibitMouse;
	static bool InhibitMousePress;
	static bool InhibitMouseRelease;

};