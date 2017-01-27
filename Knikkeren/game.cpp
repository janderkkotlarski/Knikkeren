#include "game.h"

Game::Game()
: m_name("Knikkeren"), m_dims(600.0f, 600.0f), m_fps(60.0f),
  m_frame(1/m_fps), m_div(10.0f), m_ball_number(100),
  m_balls(m_ball_number, m_dims, m_fps, m_div, m_seed),
  m_seed(std::chrono::system_clock::now().time_since_epoch().count()),
  m_background(127, 63, 31), m_filler(223, 127, 95),
  m_window(sf::VideoMode(m_dims.x, m_dims.y), m_name, sf::Style::Default)
{
    assert(m_name != "");
    assert(m_dims.x > 0.0f);
    assert(m_dims.y > 0.0f);
    assert(m_fps > 0.0f);
    assert(m_div >= 2.0f);
    assert(m_ball_number > 0);
}

void Game::run()
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

        m_balls.display(m_window);

        m_window.display();

        m_balls.moving();

        time = clock.getElapsedTime();

        while(time.asSeconds() < m_frame)
        {
            time = clock.getElapsedTime();
        }
    }
}
