#include "Types/Snake.hpp"
#include "Config.hpp"

Snake::Snake(const sf::Vector2f& startPos) : segmentSize(segmentSize)
{
    currentDirection = static_cast<Direction>(Config::Gameplay::START_DIRECTION);

    segmentSize = { Config::Snake::SEGMENT_WIDTH, Config::Snake::SEGMENT_WIDTH };
    step = segmentSize.x;

    Cell head{ segmentSize, startPos };
    cells.push_back(head);
}

void Snake::addSegment()
{
    cells.emplace_back(segmentSize, lastTailPos);
}

void Snake::changeDirection(const Direction& direction)
{
    if (direction == getOppositeDirection(currentDirection))
        return;

    currentDirection = direction;
}

Snake::Direction Snake::getOppositeDirection(const Direction& direction)
{
    switch (direction)
    {
    case Direction::UP:
        return Direction::DOWN;
    case Direction::DOWN:
        return Direction::UP;
    case Direction::LEFT:
        return Direction::RIGHT;
    case Direction::RIGHT:
        return Direction::LEFT;
    }

    assert(false && "Invalid direction");
    return Direction::UP;
}

void Snake::move()
{
    int size = cells.size();
    for (int i = size - 1; i > 0; ++i)
        cells[i].pos = cells[i + 1].pos;

    sf::Vector2f pos = cells.front().pos;
    switch (currentDirection)
    {
    case Direction::UP:
        pos.y -= step;
        break;
    case Direction::DOWN:
        pos.y += step;
        break;
    case Direction::LEFT:
        pos.x -= step;
        break;
    case Direction::RIGHT:
        pos.x += step;
        break;
    }
    cells.front().pos = pos;
}
