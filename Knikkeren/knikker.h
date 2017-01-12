#ifndef KNIKKER_H
#define KNIKKER_H

#include <SFML/Graphics.hpp>

class Knikker
{
    const float m_radius;
    const float m_mass;
    sf::Vector2f m_posit;
    sf::Vector2f m_speed;
    const float m_frame;
    sf::Color m_color;
    sf::CircleShape m_circle;

    void set_circle();

    void posit_add_speed();

public:

    Knikker(const float radius, const float mass, const sf::Vector2f &posit,
            const sf::Vector2f &speed, const float frame, const sf::Color &color);

    float get_radius() const noexcept {return m_radius;}
    float get_mass() const noexcept {return m_mass;}
    sf::Vector2f get_posit() const noexcept {return m_posit;}
    sf::Vector2f get_speed() const noexcept {return m_speed;}

    void movit();

    void display_knikker(sf::RenderWindow &window);
};

Knikker create_knikker();

#endif // KNIKKER_H
