#include "Events/EventHandler.hpp"
#include "Types/Snake.hpp"

void EventHandler::processWindowClose(const std::optional<sf::Event>& event, sf::RenderWindow& window)
{
    if (event->is<sf::Event::Closed>())
        window.close();
}

void EventHandler::processKeyPress(const std::optional<sf::Event>& event, SnakeBase* snake)
{
    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (!snake)
            return;

        switch (keyPressed->code)
        {
        case sf::Keyboard::Key::Up:
        case sf::Keyboard::Key::W:
            snake->changeDirection(SnakeBase::Direction::UP);
            break;
        case sf::Keyboard::Key::Down:
        case sf::Keyboard::Key::S:
            snake->changeDirection(SnakeBase::Direction::DOWN);
            break;
        case sf::Keyboard::Key::Left:
        case sf::Keyboard::Key::A:
            snake->changeDirection(SnakeBase::Direction::LEFT);
            break;
        case sf::Keyboard::Key::Right:
        case sf::Keyboard::Key::D:
            snake->changeDirection(SnakeBase::Direction::RIGHT);
            break;
        }
    }
}
