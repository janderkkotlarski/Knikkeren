#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "knikker.h"
#include "bollen.h"

class Game
{
    const std::string m_name;

    const sf::Vector2f m_dims;

    const float m_fps; // Zero Punctuation Stereotype
    const float m_frame;

    const sf::Color m_background;
    const sf::Color m_filler;

    sf::RenderWindow m_window;

public:

    Game();

    void run();
};

#endif // GAME_H
