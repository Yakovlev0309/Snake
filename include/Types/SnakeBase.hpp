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

    virtual void create(const sf::Vector2i& startPos) = 0;
    virtual void changeDirection(const Direction& direction) = 0;
    virtual void move() = 0;
    virtual bool canEat(const Cell& food) const = 0;
    virtual void eat() = 0;
    virtual bool checkLose() const = 0;
    virtual void onLose() = 0;
    const std::vector<Cell>& getCells() const { return cells; }

protected:
    std::vector<Cell> cells;
};
