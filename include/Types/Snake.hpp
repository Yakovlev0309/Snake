#pragma once

#include <vector>

#include "Types/SnakeBase.hpp"

class Snake : public SnakeBase
{
public:
    Snake();
    
    void create(const sf::Vector2i& startPos) override;
    void changeDirection(const Direction& direction) override;
    void move() override;
    bool canEat(const Cell& food) const override;
    void eat() override;
    bool checkLose() const override;
    void onLose() override;

private:
    Snake::Direction getOppositeDirection(const Direction& direction);

    sf::Vector2i segmentSize;
    sf::Vector2i lastTailPos;
    Direction currentDirection;
};
