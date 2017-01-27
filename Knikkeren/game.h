#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "marble.h"
#include "balls.h"

class Game
{
    const std::string m_name;

    const sf::Vector2f m_dims;

    const float m_fps; // Zero Punctuation Stereotype
    const float m_frame;
    const float m_div;

    const int m_ball_number;
    Balls m_balls;

    unsigned m_seed;

    const sf::Color m_background;
    const sf::Color m_filler;

    sf::RenderWindow m_window;

public:

    Game();

    void run();
};

#endif // GAME_H
