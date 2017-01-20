#include "bollen.h"

void Bollen::plaats_knikkers()
{
    for (int count{0}; count < m_aantal; ++count)
    {
        Knikker knik{random_knikker(m_dims, 1.0f/m_fps)};

        // std::cout << "Knik\n";

        if (count > 0)
        {
            bool colli{true};

            while (colli)
            {
                colli = false;

                for (int count_2{0}; count_2 < count; ++count_2)
                {
                    if (botsing(knik, m_knikkers[count_2]))
                    {
                        colli = true;
                    }
                }
            }
        }

        m_knikkers.push_back(knik);

        // std::cout << "Pushed\n";
    }
}

void Bollen::display(sf::RenderWindow &window) const
{
    for (int count{0}; count < m_aantal; ++count)
    {
        m_knikkers[count].display_knikker(window);
    }
}

void Bollen::move()
{
    for (int count{0}; count < m_aantal; ++count)
    {
        m_knikkers[count].movit();
    }

    for (int count{0}; count < m_aantal - 1; ++count)
    {
        for (int count_2{count + 1}; count_2 < m_aantal; ++count_2)
        {
            if (botsing(m_knikkers[count], m_knikkers[count_2]))
            {
                m_knikkers[count].reflect();
                m_knikkers[count_2].reflect();
            }
        }
    }
}

Bollen::Bollen(const int aantal, const sf::Vector2f &dims, const float fps)
    : m_aantal(aantal), m_knikkers(), m_dims(dims), m_fps(fps)
{
    assert(m_aantal > 0);
    assert(m_dims.x > 0.0f);
    assert(m_dims.y > 0.0f);
    assert(m_fps > 0.0f);

    plaats_knikkers();
}




