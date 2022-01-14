#include "GUI.hpp"                                                                                                                                                                 
#include "Config.hpp"                                                                                                                                                              
#include <cmath>                                                                                                                                                                   
#include <string>                                                                                                                                                                  
#include "stats.hpp"                                                                                                                                                               
                                                                                                                                                                                   
                                 
                                                                                             
int main()                                                                                   
{                                                                                            
    Config con;                                                                              
    GUI button[2];   
    button[0].setButton(100,100,100,100,sf::Color::White);                                     
    button[1].setButton(50,50,50,50,sf::Color::White);                                                   
                                                                 
    sf::Text textbox;                                                                           
    sf::RenderWindow window(sf::VideoMode(500, 500), "Demo Tool");                             
                                                                                             
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
                    if(button[0].buttonPressed(p)){                                     
                        printf("%d",setCreature()->getName());                                            
                    }                                                                   
                    else if(button[1].buttonPressed(p)){                                
                        printf("penis2");                                               
                    }                                                                   
                                                                                        
                                                                            
                }                                                                
                if (event.type == sf::Event::Closed)                             
                {                                                                
                    window.close();                                              
                }                                                                
            }                                                                    
        }                                                                   
        window.clear();                                                     
        for (int i = 0; i <= 1; i++)                                        
        {                                                                   
            window.draw(button[i].getButton());                             
        }                                                                   
        window.display();           
                                                       
    }                                                                            
                                                                                 
    return 0;                                                                    
}                                                   
                                                    
                                                    