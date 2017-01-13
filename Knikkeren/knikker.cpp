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

void Knikker::minflect()
{
    if (m_posit.x < m_radius)
    {
        m_posit.x += 2.0f*(m_radius - m_posit.x);
        m_speed.x *= -1.0f;
    }

    if (m_posit.y < m_radius)
    {
        m_posit.y += 2.0f*(m_radius - m_posit.y);
        m_speed.y *= -1.0f;
    }
}

void Knikker::maxflect()
{
    if (m_posit.x > m_dims.x - m_radius)
    {
        m_posit.x -= 2.0f*(m_posit.x + m_radius - m_dims.x);
        m_speed.x *= -1.0f;
    }

    if (m_posit.y > m_dims.y - m_radius)
    {
        m_posit.y -= 2.0f*(m_posit.y + m_radius - m_dims.y);
        m_speed.y *= -1.0f;
    }
}

void Knikker::wall_reflect()
{
    minflect();
    maxflect();
}


Knikker::Knikker(const float mass, const float radius, const sf::Vector2f &dims, const sf::Vector2f &posit,
                 const sf::Vector2f &speed, const float frame, const sf::Color &color)
    : m_mass(mass), m_radius(radius), m_dims(dims), m_posit(posit), m_speed(speed), m_frame(frame),
      m_color(color), m_circle()
{
    set_circle();
}

void Knikker::movit()
{
    posit_add_speed();
    wall_reflect();
}

void Knikker::display_knikker(sf::RenderWindow &window) const
{
    window.draw(m_circle);
}

Knikker create_knikker() noexcept
{
    return Knikker(1.0f, 5.0f, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(100.0f, 100.0f),
                   sf::Vector2f(0.0f, 0.0f), 1.0f/60.0f, sf::Color(191, 191, 191));
}
