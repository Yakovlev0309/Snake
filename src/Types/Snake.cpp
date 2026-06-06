#include "Types/Snake.hpp"
#include "Config.hpp"

Snake::Snake(const sf::Vector2i& startPos) : segmentSize(segmentSize), lastTailPos(startPos)
{
    currentDirection = static_cast<Direction>(Config::Gameplay::START_DIRECTION);

    segmentSize = { Config::Objects::SEGMENT_WIDTH, Config::Objects::SEGMENT_WIDTH };

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
    lastTailPos = cells.back().pos;

    int size = cells.size();
    for (int i = size - 1; i > 0; --i)
        cells[i].pos = cells[i - 1].pos;

    switch (currentDirection)
    {
    case Direction::UP:
        --cells.front().pos.y;
        if (cells.front().pos.y < 0)
            cells.front().pos.y = Config::Game::GRID_HEIGHT - 1;
        break;
    case Direction::DOWN:
        ++cells.front().pos.y;
        if (cells.front().pos.y >= Config::Game::GRID_HEIGHT)
            cells.front().pos.y = 0;
        break;
    case Direction::LEFT:
        --cells.front().pos.x;
        if (cells.front().pos.x < 0)
            cells.front().pos.x = Config::Game::GRID_WIDTH;
        break;
    case Direction::RIGHT:
        ++cells.front().pos.x;
        if (cells.front().pos.x >= Config::Game::GRID_WIDTH)
            cells.front().pos.x = 0;
        break;
    }
}
