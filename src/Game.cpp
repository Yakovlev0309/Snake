#include "Game.hpp"
#include "Log/LogSystem.hpp"
#include "Config.hpp"
#include "Types/Cell.hpp"

Game::Game() 
    : window(
        sf::VideoMode({ GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT }),
        GameConfig::GAME_NAME
    ),
    renderer(window)
{
    window.setFramerateLimit(GameConfig::FRAMERATE_LIMIT);

    renderer.setColor(sf::Color::Red); // test
}

void Game::run()
{
    Log::info("Running");

    float dt;

    while (window.isOpen())
    {
        processEvents();

        dt = clock.restart().asSeconds();
        update(dt);

        render();
    }

    Log::info("Game quit");
}

void Game::processEvents()
{
    while (const auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Game::update(float dt)
{
    // game logic
}

void Game::render()
{
    window.clear();

    renderer.drawCell(Cell{ {60.f, 60.f}, {100.f, 100.f} });

    window.display();
}
