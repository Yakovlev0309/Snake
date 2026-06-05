#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Render/Renderer.hpp"

class Game
{
public:
    Game();

    void run();
    void processEvents();
    void update(float dt);
    void render();
    
private:
    sf::RenderWindow window;
    Renderer renderer;
    sf::Clock clock;
};
