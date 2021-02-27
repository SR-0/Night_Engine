#include "Render.h"

void Render::execute()
{
	// **clear frame**
	m_RenderWindow->clear();

	// **draw frame** - for every layer, draw that layer
	for (unsigned int renderLayer = 1; renderLayer < *m_RenderLayerCount + 1; renderLayer++)
	{
		const unsigned int iterations = (m_RectangleShapes->objectCount() > m_Texts->objectCount() ? m_RectangleShapes->objectCount() : m_Texts->objectCount());

		// draw rectangle shapes
		for (unsigned int position = 0; position < iterations; position++)
		{
			// check if rectangle is enabled to be rendered and if its on this render layer
			if (position < m_RectangleShapes->objectCount()
				&& m_RectangleShapes->get(position).isRenderEnabled() 
				&& m_RectangleShapes->get(position).getRenderLayer() == renderLayer)
			{
				// render rectangle shape in this position of the rectangle shape array
				m_RenderWindow->draw(m_RectangleShapes->get(position));
			}

			// check if text is enabled to be rendered and if its on this render layer
			if (position < m_Texts->objectCount()
				&& m_Texts->get(position).isRenderEnabled()
				&& m_Texts->get(position).getRenderLayer() == renderLayer)
			{
				// render Text in this position of the text array
				m_RenderWindow->draw(m_Texts->get(position));
			}
		}
	}

	// **display frame**
	m_RenderWindow->display();
}