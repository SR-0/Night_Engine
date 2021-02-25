#pragma once

#include <SFML/Graphics/Text.hpp>

class Text : public sf::Text
{
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

	bool			m_RenderEnabled = false;
	unsigned int	m_RenderLayer	= 0;

};