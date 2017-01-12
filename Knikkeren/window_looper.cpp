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

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        m_window.clear(m_background);

        m_window.display();
    }
}
