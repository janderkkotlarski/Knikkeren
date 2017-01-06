#ifndef WINDOW_LOOPER_H
#define WINDOW_LOOPER_H

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

class Window_Looper
{
    const std::string m_name{"Knikkeren"};

    const sf::Vector2f m_dims{600.0f, 600.0f};

    const float m_fps{60}; // Zero Punctuation Stereotype
    const float m_frame{1/m_fps};

    const sf::Color m_background{127, 63, 31};
    const sf::Color m_filler{223, 127, 95};

public:

    Window_Looper();

    void winloop();

};

#endif // WINDOW_LOOPER_H
