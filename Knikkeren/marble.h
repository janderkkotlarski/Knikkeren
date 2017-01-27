#ifndef MARBLE_H
#define MARBLE_H

#include <cassert>
#include <SFML/Graphics.hpp>

class Marble
{
    const float m_mass;
    const sf::Vector2f m_dims;
    sf::Vector2f m_speed;
    const float m_frame;
    const float m_div;
    sf::CircleShape m_circle;
    sf::Vector2f m_past;

    void set_past() noexcept {m_past = m_circle.getPosition();}

    void add_speed();

    void collide_wall();

    void move_cycle();

public:

    void set_circle(const float radius, const sf::Vector2f &posit, const sf::Color &color);

    explicit Marble(const float mass, const float radius, const sf::Vector2f &dims, const sf::Vector2f &posit,
                    const sf::Vector2f &speed, const float frame, const float div, const sf::Color &color);

    float get_radius() const noexcept {return m_circle.getRadius();}
    float get_mass() const noexcept {return m_mass;}
    sf::Vector2f get_posit() const noexcept {return m_circle.getPosition();}
    sf::Vector2f get_speed() const noexcept {return m_speed;}

    void set_speed(const sf::Vector2f &speed) {m_speed = speed;}

    void movit();

    void display_marble(sf::RenderWindow &window) const;
};

float walled(const float wall, const float current, const float radius, float &veloc);

sf::Vector2f distance(const sf::Vector2f &posit_1, const sf::Vector2f &posit_2) noexcept;

float vectuare(const sf::Vector2f &vect) noexcept;

float square(const float scalar) noexcept;

bool overlap(Marble &marb_1, Marble &marb_2);

void simpflect(Marble &marb_1, Marble &marb_2);

#endif // MARBLE_H
