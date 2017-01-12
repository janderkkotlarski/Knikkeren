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
}
