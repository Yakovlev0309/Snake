#include "Render/SnakeRenderer.hpp"
#include "Types/SnakeBase.hpp"
#include "Config.hpp"

void SnakeRenderer::drawSnake(const SnakeBase& snake)
{
    const auto& cells = snake.getCells();
    drawCell(cells.front()); // Drawing head
    for (int i = 1; i < cells.size(); ++i)
        CellRenderer::drawCell(cells[i]);
}

void SnakeRenderer::drawCell(const Cell& cell)
{
    // This function overrided only for head drawing

    headRect.setSize({ (float)cell.size.x, (float)cell.size.y });
    headRect.setPosition({
        (float)(cell.pos.x * Config::Objects::SEGMENT_WIDTH),
        (float)(cell.pos.y * Config::Objects::SEGMENT_WIDTH)
    });

    window.draw(headRect);
}

void SnakeRenderer::setHeadColor(const sf::Color& color)
{
    headRect.setFillColor(color);
}
