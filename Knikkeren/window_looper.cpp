#include "window_looper.h"

Window_Looper::Window_Looper()
: m_window(sf::VideoMode(m_dims.x, m_dims.y), m_name, sf::Style::Default)
{
}

void Window_Looper::winloop()
{
    while(m_window.isOpen())
    {
        sf::Event event;
        sf::Clock clock;
        sf::Time time;

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                m_window.close();
            }
        }

        m_window.clear(m_background);
        m_window.display();

        time = clock.getElapsedTime();

        while(time.asSeconds() < m_frame)
        {
            time = clock.getElapsedTime();
        }
    }
}
