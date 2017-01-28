#ifndef TEXT_H
#define TEXT_H

#include <cassert>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

class Text
{
    const std::string m_filename;
    const std::string m_name;
    const float m_scale;
    const sf::Vector2f m_posit;
    const float m_size;
    const sf::Color m_color;
    sf::Font m_font;
    sf::Text m_text;

    void initialize();

public:

    Text(const std::string &name, const sf::Vector2f &dims);

    void float_stringer(const float number) {m_text.setString(m_name + std::to_string(number));}

    void display(sf::RenderWindow &window) const noexcept {window.draw(m_text);}

};

#endif // TEXT_H
