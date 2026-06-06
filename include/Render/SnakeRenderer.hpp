#pragma once

#include "Render/CellRenderer.hpp"

class SnakeBase;

class SnakeRenderer : public CellRenderer
{
public:
    SnakeRenderer(sf::RenderWindow& window) : CellRenderer(window) {}

    void drawSnake(const SnakeBase& snake);
};
