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
    // const sf::Vector2f my_little_speedling{0.3f*m_dims.x, 0.23f*m_dims.y};

    // Knikker knikker(1.0f, 0.1f*m_dims.x, m_dims, 0.5f*m_dims, my_little_speedling, m_frame, m_filler);

    // Knikker gnigger{create_knikker()};

    // std::vector <Knikker> marbles;

    // for

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    Bollen bollen(10, m_dims, m_fps, seed);


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
        // knikker.display_knikker(m_window);
        // gnigger.display_knikker(m_window);
        bollen.display(m_window);
        m_window.display();

        // knikker.movit();
        // gnigger.movit();
        bollen.move();

        time = clock.getElapsedTime();

        while(time.asSeconds() < m_frame)
        {
            time = clock.getElapsedTime();
        }
    }
}
