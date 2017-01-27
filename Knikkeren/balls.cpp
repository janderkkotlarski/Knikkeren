#include "balls.h"

void Balls::place_marbles(unsigned &seed)
{
    for (int count{0}; count < m_number; ++count)
    {
        bool overlappen = true;

        while (overlappen)
        {
            overlappen = false;

            Marble knik{random_marble(m_dims, 1.0f/m_fps, seed)};

            if (count > 0)
            {
                for (Marble knak: m_marbles)
                {
                    if (overlap(knik, knak))
                    {
                        overlappen = true;
                    }
                }
            }

            if (!overlappen)
            {
                m_marbles.push_back(knik);
            }
        }
    }
}

void Balls::move()
{
    for (unsigned count{0}; count < m_marbles.size(); ++count)
    {
        m_marbles[count].movit();
    }
}

void Balls::marbflect()
{
    for (unsigned count_1{1}; count_1 < m_marbles.size(); ++count_1)
    {
        for (unsigned count_2{0}; count_2 < count_1; ++count_2)
        {
            simpflect(m_marbles[count_1], m_marbles[count_2]);
        }
    }
}

Balls::Balls(const int number, const sf::Vector2f &dims, const float fps, unsigned &seed)
    : m_number(number), m_marbles(), m_dims(dims), m_fps(fps)
{
    assert(m_number > 0);
    assert(m_dims.x > 0.0f);
    assert(m_dims.y > 0.0f);
    assert(m_fps > 0.0f);

    place_marbles(seed);
}

void Balls::display(sf::RenderWindow &window)
{
    for (Marble knak: m_marbles)
    {
        knak.display_marble(window);
    }
}

void Balls::moving()
{
    move();
    marbflect();
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

float random_frac(unsigned &seed)
{
    std::mt19937_64 rand(seed);

    const float rando{static_cast<float>(rand())};
    const float maxo{static_cast<float>(rand.max())};

    ++seed;

    return rando/maxo;
}

float random_mass(unsigned &seed)
{
    const float min_frac{0.01f};
    assert(min_frac >= 0.01f);
    assert(min_frac < 0.2f);

    return min_frac + random_frac(seed)*(1.0f - min_frac);
}

float random_radius(const sf::Vector2f &dims, unsigned &seed)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float perc{0.05f};
    assert(perc > 0.0f);
    assert(perc <= 0.2f);

    const float min_perc{0.01f};
    assert(min_perc > 0.0f);
    assert(min_perc < 0.2f);

    return (min_perc + random_frac(seed)*(perc - min_perc))*medims(dims);
}

sf::Vector2f random_posit(const float radius, const sf::Vector2f &dims, unsigned &seed)
{
    assert(radius > 0.0f);
    assert(radius < 0.5f*dims.x);
    assert(radius < 0.5f*dims.y);

    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    return sf::Vector2f(radius + random_frac(seed)*(dims.x - 2.0f*radius),
                        radius + random_frac(seed)*(dims.y - 2.0f*radius));
}

sf::Vector2f random_speed(const sf::Vector2f &dims, unsigned &seed)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float perc{0.5f};
    assert(perc > 0.0f);
    assert(perc <= 0.5f);

    const float speed{(random_frac(seed) - 0.5f)*perc*medims(dims)};

    const float phi{random_frac(seed)*2.0f*3.14159f};

    return sf::Vector2f(cos(phi)*speed, sin(phi)*speed);
}

sf::Color random_color(unsigned &seed)
{
    const float min_frac{0.5f};
    assert(min_frac >= 0.0f);
    assert(min_frac < 1.0f);

    return sf::Color(frac_to_byte(min_frac + random_frac(seed)*(1.0f - min_frac)),
                     frac_to_byte(min_frac + random_frac(seed)*(1.0f - min_frac)),
                     frac_to_byte(min_frac + random_frac(seed)*(1.0f - min_frac)));
}

Marble random_marble(const sf::Vector2f &dims, const float frame, unsigned &seed)
{
    assert(dims.x > 0.0f);
    assert(dims.y > 0.0f);

    const float radius{random_radius(dims, seed)};

    return Marble(random_mass(seed), radius, dims, random_posit(radius, dims, seed),
                   random_speed(dims, seed), frame, random_color(seed));
}
