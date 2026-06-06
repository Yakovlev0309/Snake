#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Render/CellRenderer.hpp"
#include "Render/SnakeRenderer.hpp"

#include <random>

class SnakeBase;
class Cell;

class Game
{
public:
    Game();
    ~Game();

    void run();
    void processEvents();
    void update(float dt);
    void render();

private:
    void spawnFood();
    bool canEat() const;
    void eat();

    sf::RenderWindow window;
    sf::Clock clock;
    CellRenderer foodRenderer;
    SnakeRenderer snakeRenderer;

    SnakeBase* snake{ nullptr };
    Cell* food{ nullptr };

    float accumulator{ 0.f };
    std::mt19937 rng{std::random_device{}()};
};
