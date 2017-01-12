#include "window_looper.h"
#include "knikker.h"

Window_Looper::Window_Looper()
: m_name("Knikkeren"), m_dims(600.0f, 600.0f), m_fps(60.0f),
  m_frame(1/m_fps), m_background(127, 63, 31), m_filler(223, 127, 95),
  m_window(sf::VideoMode(m_dims.x, m_dims.y), m_name, sf::Style::Default)
{
}

void Window_Looper::winloop()
{
    Knikker knikker(0.1f*m_dims.x, 1.0f, 0.5f*m_dims, 0.0f*m_dims, m_filler);

    Knikker gnigger{create_knikker()};


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
        knikker.display_knikker(m_window);
        gnigger.display_knikker(m_window);
        m_window.display();

        time = clock.getElapsedTime();

        while(time.asSeconds() < m_frame)
        {
            time = clock.getElapsedTime();
        }
    }
}
