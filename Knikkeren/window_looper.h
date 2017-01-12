#ifndef WINDOW_LOOPER_H
#define WINDOW_LOOPER_H

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Window_Looper
{
    const std::string m_name;

    const sf::Vector2f m_dims;

    const float m_fps; // Zero Punctuation Stereotype
    const float m_frame;

    const sf::Color m_background;
    const sf::Color m_filler;

    sf::RenderWindow m_window;

public:

    Window_Looper();

    void winloop();
};

#endif // WINDOW_LOOPER_H
