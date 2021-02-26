#include "Input.h"

	bool Input::InhibitKeyboard			= false;
	bool Input::InhibitKeyboardPress	= false;
	bool Input::InhibitKeyboardRelease	= false;

	bool Input::InhibitMouse			= false;
	bool Input::InhibitMousePress		= false;
	bool Input::InhibitMouseRelease		= false;

bool Input::leftClickPressedOver(sf::RectangleShape& rectangleShape, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
		&& (sf::Mouse::getPosition(window).x > (int)rectangleShape.getPosition().x) 
		&& (sf::Mouse::getPosition(window).x < (int)rectangleShape.getPosition().x + ((int)rectangleShape.getSize().x * rectangleShape.getScale().x)) 
		&& (sf::Mouse::getPosition(window).y > (int)rectangleShape.getPosition().y) 
		&& (sf::Mouse::getPosition(window).y < (int)rectangleShape.getPosition().y + ((int)rectangleShape.getSize().y * rectangleShape.getScale().y)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
