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

    food = new Cell();
    food->size = { Config::Objects::SEGMENT_WIDTH, Config::Objects::SEGMENT_WIDTH };

    snake = new Snake();
}

Game::~Game()
{
    delete snake;
    delete food;
}

void Game::run()
{
    Log::info("Running");

    initObjects();

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

void Game::initObjects()
{
    sf::Vector2i startPos{
        Config::Game::GRID_WIDTH / 2,
        Config::Game::GRID_HEIGHT / 2,
    };
    snake->create(startPos);

    spawnFood();
}

void Game::spawnFood()
{
    std::uniform_int_distribution<int> xDist(0, Config::Game::GRID_WIDTH - 1);
    std::uniform_int_distribution<int> yDist(0, Config::Game::GRID_HEIGHT - 1);

    food->pos = {
        (int)xDist(rng),
        (int)yDist(rng)
    };
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

    if (snake->checkLose())
    {
        onLose();
        return;
    }

    if (snake->canEat(*food))
        onEat();
}

void Game::onEat()
{
    snake->eat();

    spawnFood();
}

void Game::onLose()
{
    snake->onLose();

    initObjects();
}

void Game::render()
{
    window.clear();

    snakeRenderer.drawSnake(*snake);
    foodRenderer.drawCell(*food);

    window.display();
}
