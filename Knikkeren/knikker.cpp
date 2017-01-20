#include "knikker.h"

void Knikker::set_circle(const float radius, const sf::Vector2f &posit, const sf::Color &color)
{
    m_circle.setRadius(radius);
    m_circle.setOrigin(radius, radius);
    m_circle.setPosition(posit);
    m_circle.setFillColor(color);
}

void Knikker::add_speed()
{
    m_circle.move(m_frame*m_speed);
}

void Knikker::minflect()
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

void Knikker::maxflect()
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

void Knikker::wall_reflect()
{
    minflect();
    maxflect();
}


Knikker::Knikker(const float mass, const float radius, const sf::Vector2f &dims,
                 const sf::Vector2f &posit, const sf::Vector2f &speed, const float frame,
                 const sf::Color &color)
    : m_mass(mass), m_dims(dims), m_speed(speed), m_frame(frame), m_circle()
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
}

void Knikker::movit()
{
    add_speed();
    wall_reflect();
}

void Knikker::display_knikker(sf::RenderWindow &window) const
{
    window.draw(m_circle);
}

Knikker create_knikker() noexcept
{
    return Knikker(1.0f, 5.0f, sf::Vector2f(600.0f, 600.0f), sf::Vector2f(100.0f, 100.0f),
                   sf::Vector2f(3.0f, 5.0f), 1.0f/60.0f, sf::Color(191, 191, 191));
}
