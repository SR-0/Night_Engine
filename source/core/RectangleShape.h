#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

class RectangleShape : public sf::RectangleShape
{
public:

	RectangleShape(const sf::Vector2f& size = sf::Vector2f(0.f, 0.f))
		:
		sf::RectangleShape(size)
	{}

public:

	void setup(
		const sf::Vector2f& size		= sf::Vector2f(0.f, 0.f),
		const sf::Vector2f& origin		= sf::Vector2f(0.f, 0.f),
		const sf::Vector2f& scale		= sf::Vector2f(1.f, 1.f),
		const sf::Vector2f& position	= sf::Vector2f(0.f, 0.f),
		const sf::Color&	color		= sf::Color::White,
		sf::Texture*		texture		= nullptr)
	{
		if (texture != nullptr)
		{
			setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
			setTexture(texture);
		}
		else
		{
			setSize(size);
		}

		setOrigin(origin);
		setScale(scale);
		setPosition(position);
		setFillColor(color);
	}

public:

	sf::Uint8 getOpacity()
	{
		return getFillColor().a;
	}

	void setOpacity(sf::Uint8 transparency)
	{
		setFillColor(sf::Color(
			getFillColor().r,
			getFillColor().g,
			getFillColor().b,
			transparency));
	}

	bool isTransparent()
	{
		if (getOpacity() > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool isOpaque()
	{
		if (getOpacity() < 255)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void fadeOut(float speed)
	{
		if ( (getOpacity() - speed) <= 0)
		{
			setOpacity(0);
		}
		else 
		{
			setOpacity(getOpacity() - speed);
		}
	}

	void fadeIn(float speed)
	{
		if ( (getOpacity() + speed) >= 255)
		{
			setOpacity(255);
		}
		else
		{
			setOpacity(getOpacity() + speed);
		}
	}

public:

	//void growWidth(float speed, float maximum)
	//{
	//	if ( (speed > 0) && (getSize().x + speed) >= abs(maximum) )
	//	{
	//		setSize(sf::Vector2f(abs(maximum), getSize().y));
	//	}
	//	else if ( (speed < 0) && (getSize().x - speed) <= - abs(maximum) )
	//	{
	//		setSize(sf::Vector2f( - abs(maximum), getSize().y) );
	//	}
	//	else
	//	{
	//		setSize(sf::Vector2f(getSize().x + speed, getSize().y));
	//	}
	//}
	//
	//void growHeight(float speed, float maximum)
	//{
	//	if ( (speed > 0) && (getSize().y + speed) >= abs(maximum))
	//	{
	//		setSize(sf::Vector2f(getSize().x, abs(maximum)));
	//	}
	//	else if ( (speed > 0) && (getSize().y - speed) <= - abs(maximum))
	//	{
	//		setSize(sf::Vector2f(getSize().x, - abs(maximum)));
	//	}
	//	else
	//	{
	//		setSize(sf::Vector2f(getSize().x, getSize().y + speed));
	//	}
	//}
	//
	//void growSize(float speedX, float speedY, float maximumX, float maximumY)
	//{
	//	growWidth(speedX, maximumX);
	//	growHeight(speedY, maximumY);
	//}

public:

	void setSpeed(const sf::Vector2f& speed)
	{
		this->m_Speed = speed;
	}

	sf::Vector2f getSpeed()
	{
		return m_Speed;
	}

public:

	void setRenderEnabled(bool renderEnabled)
	{
		this->m_RenderEnabled = renderEnabled;
	}

	bool isRenderEnabled()
	{
		return m_RenderEnabled;
	}

public:

	void setRenderLayer(unsigned int renderLayer)
	{
		this->m_RenderLayer = renderLayer;
	}

	bool getRenderLayer()
	{
		return m_RenderLayer;
	}

private:

	sf::Vector2f	m_Speed			= sf::Vector2f();
	bool			m_RenderEnabled = false;
	unsigned int	m_RenderLayer	= 0;

};

