#include "Render/Renderer.hpp"
#include "Types/Cell.hpp"

void Renderer::drawCell(const Cell& cellData)
{
    cell.setSize({ cellData.size.x, cellData.size.y });
    cell.setPosition({ cellData.pos.x, cellData.pos.y });

    window.draw(cell);
}

void Renderer::setColor(const sf::Color& color)
{
    cell.setFillColor(color);
}
