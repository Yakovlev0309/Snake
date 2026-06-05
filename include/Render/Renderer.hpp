#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Cell;

class Renderer
{
public:
    Renderer(sf::RenderWindow& window) : window(window) {}

    void drawCell(const Cell& cellData);
    void setColor(const sf::Color& color);

private:
    sf::RenderWindow& window;
    sf::RectangleShape cell;
};
