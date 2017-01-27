#include "marble.h"

void Marble::set_circle(const float radius, const sf::Vector2f &posit, const sf::Color &color)
{
    m_circle.setRadius(radius);
    m_circle.setOrigin(radius, radius);
    m_circle.setPosition(posit);
    m_circle.setFillColor(color);
}

void Marble::collide_wall()
{
    m_circle.setPosition(walled(m_dims.x, m_circle.getPosition().x, m_circle.getRadius(), m_speed.x),
                         walled(m_dims.y, m_circle.getPosition().y, m_circle.getRadius(), m_speed.y));
}

void Marble::move_cycle()
{
    set_past();
    add_speed(m_diframe);
    collide_wall();
}

Marble::Marble(const float mass, const float radius, const sf::Vector2f &dims,
                 const sf::Vector2f &posit, const sf::Vector2f &speed, const float frame,
                 const float div, const sf::Color &color)
    : m_mass(mass), m_dims(dims), m_speed(speed), m_frame(frame),
      m_diframe(m_frame/div), m_circle(), m_past()
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
    assert(m_diframe > 0.0f);
    assert(m_diframe < 1.0f);

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

float repolate(Marble &marb_1, Marble &marb_2)
{
    const sf::Vector2f dist{distance(marb_1.get_posit(), marb_2.get_posit())};
    const sf::Vector2f fast{distance(marb_1.get_speed(), marb_2.get_speed())};

    const float diframe{0.5f*(marb_1.get_diframe() + marb_2.get_diframe())};

    const float radi_2{square(marb_1.get_radius() + marb_2.get_radius())};

    const float alpha{vectuare(fast)};

    const float beta{2.0f*(dist.x*fast.x + dist.y*fast.y)};

    const float gamma{vectuare(dist) - radi_2};

    const float delta{std::sqrt(square(beta) - 4.0f*alpha*gamma)};

    const float deltime_p{0.5f*diframe*(delta - beta)/alpha};

    const float deltime_n{0.5f*diframe*(-delta - beta)/alpha};

    if (deltime_n < deltime_p)
    {
        return diframe - deltime_n;
    }

    return diframe - deltime_p;
}

void simpflect(Marble &marb_1, Marble &marb_2)
{
    if (overlap(marb_1, marb_2))
    {
        marb_1.set_speed(-marb_1.get_speed());
        marb_2.set_speed(-marb_2.get_speed());

        const float period{2.0f*repolate(marb_1, marb_2)};

        marb_1.add_speed(period);
        marb_2.add_speed(period);
    }
}

void realflect(Marble &marb_1, Marble &marb_2)
{
    if (overlap(marb_1, marb_2))
    {
        const float period{-repolate(marb_1, marb_2)};

        marb_1.add_speed(period);
        marb_2.add_speed(period);

        const sf::Vector2f speed_1{marb_1.get_speed()};
        const sf::Vector2f speed_2{marb_2.get_speed()};

        const sf::Vector2f delta_speed{distance(speed_1, speed_2)};


    }
}
