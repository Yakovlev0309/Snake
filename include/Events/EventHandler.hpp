#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class SnakeBase;

class EventHandler
{
public:
    static void processWindowClose(const std::optional<sf::Event>& event, sf::RenderWindow& window);
    static void processKeyPress(const std::optional<sf::Event>& event, SnakeBase* snake);
};