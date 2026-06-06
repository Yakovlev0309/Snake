#pragma once

#include "Types/Cell.hpp"

class SnakeBase
{
public:
    enum class Direction
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT
    };

    virtual void changeDirection(const Direction& newDirection) = 0;
    virtual void move() = 0;
    virtual void addSegment() = 0;
    const std::vector<Cell>& getCells() const { return cells; }

protected:
    std::vector<Cell> cells;
};
