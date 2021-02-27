#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class CollisionDetection
{
public:

	CollisionDetection(const sf::Vector2f& position = sf::Vector2f(), const sf::Vector2f& size = sf::Vector2f(), const sf::Vector2f& scale = sf::Vector2f())
		:
		m_Position(position),
		m_Size(size),
		m_Scale(scale)
	{}

public:

	sf::FloatRect getBounds()
	{
		return sf::FloatRect(sf::Vector2f(m_Position), sf::Vector2f(m_Size.x * m_Scale.x, m_Size.y * m_Scale.y));
	}

	bool collidesWith(sf::FloatRect rect)
	{

	}

public:

	sf::Vector2f m_Position;
	sf::Vector2f m_Size;
	sf::Vector2f m_Scale;

};