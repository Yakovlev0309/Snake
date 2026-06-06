#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Render/CellRenderer.hpp"
#include "Render/SnakeRenderer.hpp"

class SnakeBase;

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
    sf::RenderWindow window;
    sf::Clock clock;
    CellRenderer foodRenderer;
    SnakeRenderer snakeRenderer;

    SnakeBase* snake{ nullptr };

    float accumulator{ 0.f };
};
