#include "Game.hpp"
#include "Log/LogSystem.hpp"
#include "Config.hpp"
#include "Types/Cell.hpp"
#include "Types/Snake.hpp"
#include "Events/EventHandler.hpp"

Game::Game()
    : window(
        sf::VideoMode({ Config::Window::WIDTH, Config::Window::HEIGHT }),
        Config::Window::GAME_NAME
    ),
    foodRenderer(window), snakeRenderer(window)
{
    window.setFramerateLimit(Config::Window::FRAMERATE_LIMIT);

    foodRenderer.setColor(sf::Color::Red);
    snakeRenderer.setColor(sf::Color::Green);

    sf::Vector2f startPos{
        window.getSize().x / 2.f,
        window.getSize().y / 2.f,
    };
    snake = new Snake(startPos);

    food = new Cell();
    food->size = {Config::Objects::SEGMENT_WIDTH, Config::Objects::SEGMENT_WIDTH};
}

Game::~Game()
{
    delete snake;
}

void Game::run()
{
    Log::info("Running");

    spawnFood();

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

void Game::spawnFood()
{
    std::uniform_int_distribution<int> xDist(0, Config::Window::WIDTH - 1 - Config::Objects::SEGMENT_WIDTH);
    std::uniform_int_distribution<int> yDist(0, Config::Window::HEIGHT - 1 - Config::Objects::SEGMENT_WIDTH);
    
    food->pos = {(float)xDist(rng), (float)yDist(rng)};
}

void Game::processEvents()
{
    while (const auto event = window.pollEvent())
    {
        EventHandler::processWindowClose(event, window);

        EventHandler::processKeyPress(event, snake);
    }
}

void Game::update(float dt)
{
    accumulator += dt;

    while (accumulator >= Config::Gameplay::SNAKE_STEP_INTERVAL)
    {
        snake->move();
        accumulator -= Config::Gameplay::SNAKE_STEP_INTERVAL;
    }
}

void Game::render()
{
    window.clear();

    snakeRenderer.drawSnake(*snake);
    foodRenderer.drawCell(*food);

    window.display();
}
