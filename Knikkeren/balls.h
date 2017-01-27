#ifndef BALLS_H
#define BALLS_H

#include <cassert>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "marble.h"

class Balls
{
    const int m_number;
    std::vector <Marble> m_marbles;
    const sf::Vector2f m_dims;
    const float m_fps;
    const float m_div;

    void place_marbles(unsigned &seed);

    void move();
    void marbflect();

public:

    explicit Balls(const int number, const sf::Vector2f &dims, const float fps, const float div, unsigned &seed);

    void display(sf::RenderWindow &window);
    void moving();
};

float medims(const sf::Vector2f &dims);

int frac_to_byte(const float frac);

float random_frac(unsigned &seed);

float random_mass(unsigned &seed);
float random_radius(const sf::Vector2f &dims, unsigned &seed);

sf::Vector2f random_posit(const float radius, const sf::Vector2f &dims, unsigned &seed);
sf::Vector2f random_speed(const sf::Vector2f &dims, unsigned &seed);

sf::Color random_color(unsigned &seed);

Marble random_marble(const sf::Vector2f &dims, const float frame, const float div, unsigned &seed);

#endif // BALLS_H
