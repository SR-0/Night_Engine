#pragma once

template<typename T>
class ObjectManager
{
public:

    ObjectManager() = default;

public:

    T* create(const T& object, const char* id)
    {
        T* t = new T(object);
        m_Objects.push_back(std::pair<T, const char*>(*t, id));
        std::cout << "ObjectManager 'create(const T& t)' function called for - memory address: " << &*t << " - ID: " << id << "\n";
        return t;
    }

    T* create(T&& object, const char* id)
    {
        T* t = new T(std::move(object));
        m_Objects.push_back(std::pair<T, const char*>(*t, id));
        std::cout << "ObjectManager 'create(T&&)' function called - memory address: " << &*t << " - ID: " << id << "\n";
        return t;
    }

    T& get(const char* id)
    {
        bool error = true;

        for (unsigned int i = 0; i < m_Objects.size(); i++)
        {
            if (&*m_Objects[i].second == &*id)
            {
                //std::cout << "ObjectManager 'get(const char*)' function called - memory address: " << &m_Objects[i] << " - ID: " << id << " -\n";
                return m_Objects[i].first;
            }
        }

        if (error)
        {
            std::cout << "ObjectManager Could not find " << id << " in container. Check spelling in root 'create' or in 'get' function parameter to make sure they match.\n";
        }
    }

    T& get(unsigned int position)
    {
        return m_Objects[position].first;
    }

    void destroy(const char* id)
    {
        for (unsigned int i = 0; i < m_Objects.size(); i++)
        {
            if (*m_Objects[i].second == *id)
            {
                m_Objects.erase(std::begin(m_Objects) + i);
            }
        }
    }

    void destroy(unsigned int position)
    {
        m_Objects.erase(std::begin(m_Objects) + position);
    }

    void destroy(unsigned int start, unsigned int end)
    {
        m_Objects.erase(std::begin(m_Objects) + start, std::begin(m_Objects) + end + 1);
    }

    void destroyAll()
    {
        m_Objects.erase(std::begin(m_Objects), std::end(m_Objects));
    }

    unsigned int objectCount()
    {
        return m_Objects.size();
    }

private:

    std::vector<std::pair<T, const char*>> m_Objects;

};