#include "Render/SnakeRenderer.hpp"
#include "Types/SnakeBase.hpp"

void SnakeRenderer::drawSnake(const SnakeBase& snake)
{
    const auto& cells = snake.getCells();
    for (auto& cell : cells)
        CellRenderer::drawCell(cell);
}
