#include "GUI.hpp"
#include "Config.hpp"
#include <cmath>
#include <string>
#include "stats.hpp"

int main()
{
    GUI textbox[7];   
    Config con;                                                                                                                     
    sf::RectangleShape background;                                                            
    background.setFillColor(sf::Color::Black);       
    int pos[3] = {550, 650, 750};                                                                                    
    background.setSize(sf::Vector2f(1000, 1000));                                             
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Demo Tool");  
    std::string playerInput;  
    int inputSpot = 0;
    int posPos = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::TextEntered)
            {

                if (event.text.unicode == '\b' && playerInput.end() != playerInput.begin())
                {
                    playerInput.erase(playerInput.end() - 1);
                }
                else
                {
                    playerInput += event.text.unicode;
                }
                if(event.text.unicode == '\x0D')
                {
                    std::cout << "enter" << std::endl;
                    inputSpot++;
                    posPos++;
                    con.array[inputSpot] = playerInput;
                    playerInput.clear();
                }
            }
            window.clear();
            textbox[inputSpot].textBox("ArialCE.ttf", playerInput, 24, sf::Color::Red, pos[posPos], 200);
            window.draw(textbox[inputSpot].gettextBox());
            window.display();
        }
    }
    return 0;
}