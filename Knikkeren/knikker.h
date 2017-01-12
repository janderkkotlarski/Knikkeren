#ifndef KNIKKER_H
#define KNIKKER_H

#include <SFML/Graphics.hpp>

class Knikker
{
    const float m_radius;
    const float m_mass;
    sf::Vector2f m_posit;
    sf::Vector2f m_speed;
    sf::Color m_color;
    sf::CircleShape m_circle;

    void set_circle();

public:

    Knikker(const float radius, const float mass, const sf::Vector2f &posit,
            const sf::Vector2f &speed, const sf::Color &color);


};

#endif // KNIKKER_H