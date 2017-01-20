#ifndef BOLLEN_H
#define BOLLEN_H

#include <cassert>
#include <vector>
#include <iostream>
#include <random>
#include <cmath>

#include <SFML/Graphics.hpp>

#include "knikker.h"

class Bollen
{
    const int m_aantal;
    std::vector <Knikker> m_knikkers;
    const sf::Vector2f m_dims;
    const float m_fps;

    void plaats_knikkers();

public:

    explicit Bollen(const int aantal, const sf::Vector2f &dims, const float fps);

    void display(sf::RenderWindow &window) const;

    void move();
};


#endif // BOLLEN_H
