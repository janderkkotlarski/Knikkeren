#ifndef GAME_H
#define GAME_H

#include <cassert>
#include <iostream>
#include <string>
#include <random>

#include <SFML/Graphics.hpp>

#include "marble.h"
#include "balls.h"
#include "text.h"

class Game
{
    const std::string m_name;

    const sf::Vector2f m_dims;

    const float m_fps; // Zero Punctuation Stereotype
    const float m_frame;
    const float m_div;

    unsigned m_seed;

    const int m_ball_number;
    Balls m_balls;

    const sf::Color m_background;
    const sf::Color m_filler;

    sf::RenderWindow m_window;
    Text m_texter;

public:

    Game();

    void floater() {m_texter.float_stringer(m_balls.total_energy());}

    void texting() noexcept {m_texter.display(m_window);}

    void run();
};

#endif // GAME_H
