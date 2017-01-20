#include "bollen.h"



void Bollen::plaats_knikkers()
{
    for (int count{0}; count < m_aantal; ++count)
    {
        Knikker knik{random_knikker(m_dims, 1.0f/m_fps)};

        if (count > 0)
        {

        }

        m_knikkers.push_back(knik);
    }
}

void Bollen::display(sf::RenderWindow &window) const
{
    for (int count{0}; count < m_aantal; ++count)
    {
        m_knikkers[count].display_knikker(window);
    }
}

void Bollen::move()
{
    for (int count{0}; count < m_aantal; ++count)
    {
        m_knikkers[count].movit();
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


