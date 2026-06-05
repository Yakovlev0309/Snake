#include <iostream>

#include <SFML/Graphics.hpp>

static sf::RenderWindow window(
    sf::VideoMode({ 800, 600 }),
    "Snake"
);

void processEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void update(float dt)
{
    // game logic
}

static sf::RectangleShape cell({ 20.f, 20.f });

void draw()
{
    cell.setPosition({ window.getSize().x / 2, window.getSize().y / 2 });
    cell.setFillColor(sf::Color::Green);

    window.draw(cell);
}

void render()
{
    window.clear();

    draw();

    window.display();
}

int main()
{
    std::cout << "Hello, Snake Game!" << std::endl;

    window.setFramerateLimit(60);

    sf::Clock clock;
    float dt;

    while (window.isOpen())
    {
        processEvents();

        dt = clock.restart().asSeconds();
        update(dt);

        render();
    }

    return 0;
}
