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
    m_circle.move(m_frame*m_speed);
}

void Marble::minflect()
{
    const float pos_x{m_circle.getPosition().x};
    const float pos_y{m_circle.getPosition().y};
    const float radius{m_circle.getRadius()};

    if (pos_x < radius)
    {
        m_circle.setPosition(2.0f*radius - pos_x, pos_y);
        m_speed.x *= -1.0f;
    }

    assert(m_circle.getPosition().x >= radius);

    const float bos_x{m_circle.getPosition().x};

    if (pos_y < radius)
    {
        m_circle.setPosition(bos_x, 2.0f*radius - pos_y);
        m_speed.y *= -1.0f;
    }

    assert(m_circle.getPosition().y >= radius);
}

void Marble::maxflect()
{
    const float pos_x{m_circle.getPosition().x};
    const float pos_y{m_circle.getPosition().y};
    const float radius{m_circle.getRadius()};

    if (pos_x > m_dims.x - radius)
    {
        m_circle.setPosition(2.0f*(m_dims.x - radius) - pos_x, pos_y);
        m_speed.x *= -1.0f;
    }

    assert(m_circle.getPosition().x <= m_dims.x - radius);

    const float bos_x{m_circle.getPosition().x};

    if (pos_y > m_dims.y - radius)
    {
        m_circle.setPosition(bos_x, 2.0f*(m_dims.y - radius) - pos_y);
        m_speed.y *= -1.0f;
    }

    assert(m_circle.getPosition().y <= m_dims.y - radius);
}

void Marble::wall_reflect()
{
    minflect();
    maxflect();
}


Marble::Marble(const float mass, const float radius, const sf::Vector2f &dims,
                 const sf::Vector2f &posit, const sf::Vector2f &speed, const float frame,
                 const sf::Color &color)
    : m_mass(mass), m_dims(dims), m_speed(speed), m_frame(frame), m_circle(), m_past()
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

    set_circle(radius, posit, color);
    set_past();
}

void Marble::movit()
{
    add_speed();
    wall_reflect();
}

void Marble::display_marble(sf::RenderWindow &window) const
{
    window.draw(m_circle);
}

void reflect_1d()
{
    // const float
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
