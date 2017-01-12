#include "knikker.h"

void Knikker::set_circle()
{
    m_circle.setRadius(m_radius);
    m_circle.setOrigin(m_radius, m_radius);
    m_circle.setPosition(m_posit);
    m_circle.setFillColor(m_color);
}


Knikker::Knikker(const float radius, const float mass, const sf::Vector2f &posit,
                 const sf::Vector2f &speed, const sf::Color &color)
    : m_radius(radius), m_mass(mass), m_posit(posit), m_speed(speed),
      m_color(color), m_circle()
{
    set_circle();
}

void Knikker::display_knikker(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

Knikker create_knikker()
{
    return Knikker(5.0f, 1.0f, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, 0.0f),
                   sf::Color(191, 191, 191));
}
