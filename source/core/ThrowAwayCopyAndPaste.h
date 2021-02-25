#pragma once

/*
	m_RenderWindow->clear();

	for (unsigned int i = 1; i < *m_RenderLayerCount + 1; i++)
	{
		if (i == 1)
		{
			std::cout << "*******\nrendering layer " << i << " out of " << *m_RenderLayerCount << " now\n";
		}
		else
		{
			std::cout << "rendering layer " << i << " out of " << *m_RenderLayerCount << " now\n";
		}

		for (unsigned int j = 0; j < m_RectangleShapes->objectCount(); j++)
		{
			if (m_RectangleShapes->get(j).isRenderEnabled() && (unsigned int)m_RectangleShapes->get(j).getRenderLayer() == i)
			{
				std::cout << "rendering RectangleShape on layer " << i << "\n";

				m_RenderWindow->draw(m_RectangleShapes->get(j));
			}
		}

		for (unsigned int j = 0; j < m_Texts->objectCount(); j++) // texts will always be after (or on top) rectangles at the moment
		{
			if (m_Texts->get(j).isRenderEnabled() && m_Texts->get(j).getRenderLayer() == i)
			{
				std::cout << "rendering Text on layer " << i << "\n";
				std::cout << "Text rendering layer " << m_Texts->get(j).getRenderLayer() << "\n";

				m_RenderWindow->draw(m_Texts->get(j));
			}
		}
	}

	m_RenderWindow->display();
*/


//// fix!!!
////template <typename T>
////class ObjectManager
////{
////public:
////
////	ObjectManager<T>() : m_Count(0)
////	{
////		this->m_Objects = new T[0];
////	}
////
////public:
////
////	void pushBack(const T& t)
////	{
////		const unsigned int newCount = m_Count + 1;
////
////		T* temp = new T[newCount];
////
////		for (unsigned int i = 0; i < m_Count; i++)
////		{
////			temp[i] = m_Objects[i];
////		}
////
////		m_Objects = nullptr;
////
////		delete m_Objects;
////
////		m_Objects = new T[newCount];
////
////		for (unsigned int i = 0; i < m_Count; i++)
////		{
////			m_Objects[i] = temp[i];
////		}
////
////		temp = nullptr;
////
////		delete temp;
////
////		m_Objects[newCount] = t;
////
////		m_Count++;
////	}
////
////public:
////
////	T*				m_Objects;
////	unsigned int	m_Count;
////
////};