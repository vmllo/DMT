#include <SFML/Graphics.hpp>
#include "Config.hpp"

int main()
{
    Config con;
    con.readText("config.txt");
    sf::RenderWindow window(sf::VideoMode(200, 200), con.array[0]);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}