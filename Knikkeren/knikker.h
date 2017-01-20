#ifndef KNIKKER_H
#define KNIKKER_H

#include <cassert>
#include <SFML/Graphics.hpp>

class Knikker
{
    const float m_mass;
    const sf::Vector2f m_dims;
    sf::Vector2f m_speed;
    const float m_frame;
    sf::CircleShape m_circle;

    void add_speed();

    void minflect();
    void maxflect();



    void wall_reflect();

public:

    void set_circle(const float radius, const sf::Vector2f &posit, const sf::Color &color);

    explicit Knikker(const float mass, const float radius, const sf::Vector2f &dims, const sf::Vector2f &posit,
            const sf::Vector2f &speed, const float frame, const sf::Color &color);

    float get_radius() const noexcept {return m_circle.getRadius();}
    float get_mass() const noexcept {return m_mass;}
    sf::Vector2f get_posit() const noexcept {return m_circle.getPosition();}
    sf::Vector2f get_speed() const noexcept {return m_speed;}

    void movit();

    void reflect();

    void display_knikker(sf::RenderWindow &window) const;
};

Knikker create_knikker() noexcept;

float square(const float linear);

sf::Vector2f distance(const sf::Vector2f &posit_a, const sf::Vector2f &posit_b);

float abstance_2(const sf::Vector2f &dist);

bool botsing(Knikker &here, Knikker &there);

float medims(const sf::Vector2f &dims);

int frac_to_byte(const float frac);

float random_frac();

float random_mass();

float random_radius(const sf::Vector2f &dims);

sf::Vector2f random_posit(const float radius, const sf::Vector2f &dims);

sf::Vector2f random_speed(const sf::Vector2f &dims);

sf::Color random_color();

Knikker random_knikker(const sf::Vector2f &dims, const float frame);

#endif // KNIKKER_H
