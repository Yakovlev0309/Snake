#include "Render/CellRenderer.hpp"
#include "Types/Cell.hpp"
#include "Config.hpp"

void CellRenderer::drawCell(const Cell& cell)
{
    cellRect.setSize({ (float)cell.size.x, (float)cell.size.y });
    cellRect.setPosition({
        (float)(cell.pos.x * Config::Objects::SEGMENT_WIDTH),
        (float)(cell.pos.y * Config::Objects::SEGMENT_WIDTH)
    });

    window.draw(cellRect);
}

void CellRenderer::setColor(const sf::Color& color)
{
    cellRect.setFillColor(color);
}
