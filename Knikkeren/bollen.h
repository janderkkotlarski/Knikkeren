#ifndef BOLLEN_H
#define BOLLEN_H

#include <cassert>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "knikker.h"

class Bollen
{
    const int m_aantal;
    std::vector <Knikker> m_knikkers;
    const sf::Vector2f m_dims;
    const float m_fps;

    void plaats_knikkers(unsigned &seed);

public:

    explicit Bollen(const int aantal, const sf::Vector2f &dims, const float fps, unsigned &seed);

    void display(sf::RenderWindow &window);

    void move();
};

float medims(const sf::Vector2f &dims);

int frac_to_byte(const float frac);

float random_frac(unsigned &seed);

float random_mass(unsigned &seed);

float random_radius(const sf::Vector2f &dims, unsigned &seed);

sf::Vector2f random_posit(const float radius, const sf::Vector2f &dims, unsigned &seed);

sf::Vector2f random_speed(const sf::Vector2f &dims, unsigned &seed);

sf::Color random_color(unsigned &seed);

Knikker random_knikker(const sf::Vector2f &dims, const float frame, unsigned &seed);

#endif // BOLLEN_H
