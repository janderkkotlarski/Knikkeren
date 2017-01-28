#include "text.h"

void Text::initialize()
{
    if (!m_font.loadFromFile(m_filename))
    {
        std::cout << m_filename << " not found!";
    }

    m_text.setFont(m_font);
    m_text.setString(m_name);
    m_text.setCharacterSize(m_size);
    m_text.setPosition(m_posit);
    m_text.setFillColor(m_color);
}

Text::Text(const std::string &name, const sf::Vector2f &dims)
    : m_filename("VeraMono-Bold.ttf"), m_name(name), m_scale(0.01f), m_posit(m_scale*dims),
      m_size(18.0f), m_color(sf::Color(255, 255, 255)), m_font(), m_text()
{
    initialize();
}
