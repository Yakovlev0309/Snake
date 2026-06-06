#pragma once

#include "Render/CellRenderer.hpp"

class SnakeBase;

class SnakeRenderer : public CellRenderer
{
public:
    SnakeRenderer(sf::RenderWindow& window) : CellRenderer(window) {}

    void drawSnake(const SnakeBase& snake);
    void drawCell(const Cell& cell) override;
    void setHeadColor(const sf::Color& color);

private:
    sf::RectangleShape headRect;
};
