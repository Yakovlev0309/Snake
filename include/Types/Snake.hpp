#pragma once

#include <vector>

#include "Types/SnakeBase.hpp"

class Snake : public SnakeBase
{
public:
    Snake(const sf::Vector2f& startPos);
    void addSegment();

    void changeDirection(const Direction& direction) override;
    void move() override;

private:
    Snake::Direction getOppositeDirection(const Direction& direction);

    sf::Vector2f segmentSize;
    sf::Vector2f lastTailPos;
    Direction currentDirection;
    float step{ 0.f };
};
