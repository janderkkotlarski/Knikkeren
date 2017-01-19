#include "bollen.h"

void Bollen::plaats_knikkers()
{
    for (int count{0}; count < m_aantal; ++count)
    {
        Knikker knik{create_knikker()};

        m_knikkers.push_back(knik);
    }
}

void Bollen::display_bollen(sf::RenderWindow &window)
{
    for (int count{0}; count < m_aantal; ++count)
    {
        m_knikkers[count].display_knikker(window);
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
