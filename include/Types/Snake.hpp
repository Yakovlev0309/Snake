#pragma once

#include <vector>

#include "Types/SnakeBase.hpp"

class Snake : public SnakeBase
{
public:
    Snake(const sf::Vector2i& startPos);
    
    void addSegment() override;
    void changeDirection(const Direction& direction) override;
    void move() override;

private:
    Snake::Direction getOppositeDirection(const Direction& direction);

    sf::Vector2i segmentSize;
    sf::Vector2i lastTailPos;
    Direction currentDirection;
};
