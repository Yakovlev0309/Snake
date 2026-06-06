#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Cell;

class CellRenderer
{
public:
    CellRenderer(sf::RenderWindow& window) : window(window) {}

    virtual void drawCell(const Cell& cell);
    void setColor(const sf::Color& color);

protected:
    sf::RenderWindow& window;
    sf::RectangleShape cellRect;
};
