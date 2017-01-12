#include "knikker.h"

void Knikker::set_circle()
{
    m_circle.setRadius(m_radius);
    m_circle.setOrigin(m_radius, m_radius);
    m_circle.setPosition(m_posit);
    m_circle.setFillColor(m_color);
}
void Knikker::posit_add_speed()
{
    m_posit += m_frame*m_speed;
    m_circle.setPosition(m_posit);
}


Knikker::Knikker(const float radius, const float mass, const sf::Vector2f &posit,
                 const sf::Vector2f &speed, const float frame, const sf::Color &color)
    : m_radius(radius), m_mass(mass), m_posit(posit), m_speed(speed), m_frame(frame),
      m_color(color), m_circle()
{
    set_circle();
}

void Knikker::movit()
{
    posit_add_speed();
}

void Knikker::display_knikker(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

Knikker create_knikker()
{
    return Knikker(5.0f, 1.0f, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(0.0f, 0.0f),
                   1.0f/60.0f, sf::Color(191, 191, 191));
}
