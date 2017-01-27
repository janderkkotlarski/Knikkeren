#include "game.h"

Game::Game()
: m_name("Knikkeren"), m_dims(600.0f, 600.0f), m_fps(60.0f),
  m_frame(1/m_fps), m_background(127, 63, 31), m_filler(223, 127, 95),
  m_window(sf::VideoMode(m_dims.x, m_dims.y), m_name, sf::Style::Default)
{
    assert(m_name != "");
    assert(m_dims.x > 0.0f);
    assert(m_dims.y > 0.0f);
    assert(m_fps > 0.0f);
}

void Game::run()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    Balls balls(100, m_dims, m_fps, seed);

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

        balls.display(m_window);
        m_window.display();

        balls.moving();

        time = clock.getElapsedTime();

        while(time.asSeconds() < m_frame)
        {
            time = clock.getElapsedTime();
        }
    }
}
