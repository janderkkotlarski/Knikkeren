#include "marble.h"

void Marble::set_circle(const float radius, const sf::Vector2f &posit, const sf::Color &color)
{
    m_circle.setRadius(radius);
    m_circle.setOrigin(radius, radius);
    m_circle.setPosition(posit);
    m_circle.setFillColor(color);
}

void Marble::add_speed()
{
    m_circle.move(m_frame*m_speed/m_div);
}

void Marble::collide_wall()
{
    m_circle.setPosition(walled(m_dims.x, m_circle.getPosition().x, m_circle.getRadius(), m_speed.x),
                         walled(m_dims.y, m_circle.getPosition().y, m_circle.getRadius(), m_speed.y));
}

void Marble::move_cycle()
{
    for (int count{0}; count < static_cast<int>(m_div); ++count)
    {
        set_past();
        add_speed();
        collide_wall();
    }
}

Marble::Marble(const float mass, const float radius, const sf::Vector2f &dims,
                 const sf::Vector2f &posit, const sf::Vector2f &speed, const float frame,
                 const float div, const sf::Color &color)
    : m_mass(mass), m_dims(dims), m_speed(speed), m_frame(frame), m_div(div), m_circle(), m_past()
{
    assert(m_mass > 0.0f);
    assert(radius > 0.0f);
    assert(posit.x >= radius);
    assert(posit.x <= m_dims.x - radius);
    assert(posit.y >= radius);
    assert(posit.y <= m_dims.y - radius);
    assert(m_speed.x < m_dims.x);
    assert(m_speed.y < m_dims.y);
    assert(m_frame > 0.0f);
    assert(m_frame < 1.0f);
    assert(m_div >= 2.0f);

    set_circle(radius, posit, color);
    set_past();
}

void Marble::movit()
{
    move_cycle();
}

void Marble::display_marble(sf::RenderWindow &window) const
{
    window.draw(m_circle);
}

float walled(const float wall, const float current, const float radius, float &veloc)
{
    if (current < radius)
    {
        veloc *= -1.0f;
        return 2.0f*radius - current;
    }

    if (current > wall - radius)
    {
        veloc *= -1.0f;
        return 2.0f*(wall - radius) - current;
    }

    return current;
}

sf::Vector2f distance(const sf::Vector2f &posit_1, const sf::Vector2f &posit_2) noexcept
{
    return posit_2 - posit_1;
}

float vectuare(const sf::Vector2f &vect) noexcept
{
    return vect.x*vect.x + vect.y*vect.y;
}

float square(const float scalar) noexcept
{
    return scalar*scalar;
}

bool overlap(Marble &marb_1, Marble &marb_2)
{
    if (vectuare(distance(marb_1.get_posit(), marb_2.get_posit())) <=
        square(marb_1.get_radius() + marb_2.get_radius()))
    {
        return true;
    }

    return false;
}

void simpflect(Marble &marb_1, Marble &marb_2)
{
    if (overlap(marb_1, marb_2))
    {
        marb_1.set_speed(-marb_1.get_speed());
        marb_2.set_speed(-marb_2.get_speed());
    }
}
