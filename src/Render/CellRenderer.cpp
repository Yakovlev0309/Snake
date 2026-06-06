#include "Render/CellRenderer.hpp"
#include "Types/Cell.hpp"

void CellRenderer::drawCell(const Cell& cell)
{
    cellRect.setSize({ cell.size.x, cell.size.y });
    cellRect.setPosition({ cell.pos.x, cell.pos.y });

    window.draw(cellRect);
}

void CellRenderer::setColor(const sf::Color& color)
{
    cellRect.setFillColor(color);
}
