#include <SFML/Graphics.hpp>                                                
#include "Config.hpp"
#include <cmath>

int main()
{
    Config con;
    con.readText("config.txt");
    sf::RenderWindow window(sf::VideoMode(200, 200), "Demo Tool");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i p = sf::Mouse::getPosition(window);
                    sf::Vector2f pp = shape.getPosition();
                    printf("%d %d\n", p.x, p.y);
                }
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}