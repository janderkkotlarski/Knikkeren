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

void Knikker::reflect()
{
    m_speed *= -1.0f;
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

float square(const float linear)
{
    return linear*linear;
}

sf::Vector2f distance(const sf::Vector2f &posit_a, const sf::Vector2f &posit_b)
{
    return posit_b - posit_a;
}

float abstance_2(const sf::Vector2f &dist)
{
    return square(dist.x) + square(dist.y);
}

bool botsing(Knikker &here, Knikker &there)
{
    const float dist_2{abstance_2(distance(here.get_posit(), there.get_posit()))};

    const float radi_2{square(here.get_radius() + there.get_radius())};

    if (dist_2 <= radi_2)
    {
        return true;
    }

    return false;
}

float medims(const sf::Vector2f &dims)
{
    assert(dims.x >0.0f);
    assert(dims.y > 0.0f);

    return 0.5f*(dims.x + dims.y);
}

int frac_to_byte(const float frac)
{
    assert(frac >= 0.0f);
    assert(frac <= 1.0f);

    return static_cast<int>(round(255.0f*frac));
}

float random_frac()
{
    std::random_device rand;

    return static_cast<float>(rand())/static_cast<float>(rand.max());
}

float random_mass()
{
    const float min_frac{0.01f};
    assert(min_frac >= 0.01f);
    assert(min_frac < 0.2f);

    return min_frac + random_frac()*(1.0f - min_frac);
}

float random_radius(const sf::Vector2f &dims)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float perc{0.05f};
    assert(perc > 0.0f);
    assert(perc <= 0.2f);

    const float min_perc{0.01f};
    assert(min_perc > 0.0f);
    assert(min_perc < 0.2f);

    return (min_perc + random_frac()*(perc - min_perc))*medims(dims);
}

sf::Vector2f random_posit(const float radius, const sf::Vector2f &dims)
{
    assert(radius > 0.0f);
    assert(radius < 0.5f*dims.x);
    assert(radius < 0.5f*dims.y);

    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    return sf::Vector2f(radius + random_frac()*(dims.x - 2.0f*radius),
                        radius + random_frac()*(dims.y - 2.0f*radius));
}

sf::Vector2f random_speed(const sf::Vector2f &dims)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float perc{0.2f};
    assert(perc > 0.0f);
    assert(perc <= 0.2f);

    const float speed{(random_frac() - 0.5f)*perc*medims(dims)};

    const float phi{random_frac()*2.0f*3.14159f};

    return sf::Vector2f(cos(phi)*speed, sin(phi)*speed);
}

sf::Color random_color()
{
    const float min_frac{0.5f};
    assert(min_frac >= 0.0f);
    assert(min_frac < 1.0f);

    return sf::Color(frac_to_byte(min_frac + random_frac()*(1.0f - min_frac)),
                     frac_to_byte(min_frac + random_frac()*(1.0f - min_frac)),
                     frac_to_byte(min_frac + random_frac()*(1.0f - min_frac)));
}

Knikker random_knikker(const sf::Vector2f &dims, const float frame)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float radius{random_radius(dims)};

    sf::Vector2f posit{random_posit(radius, dims)};

    return Knikker(random_mass(), radius, dims, posit,
                   random_speed(dims), frame, random_color());
}
