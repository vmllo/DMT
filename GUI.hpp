                                                                                     
#ifndef GUI_HPP
#define GUI_HPP
               
               
#include <SFML/Graphics.hpp>      
#include <string>                                                    
                                                                                                          
class GUI                                                                               
{                                                                                                         
public:                                                                                                   
    void setButton(float sizex, float sizey, float posx, float posy, sf::Color color)                     
    {                                                                                                     
        button.setSize(sf::Vector2f(sizex, sizey));                                                       
        button.setPosition(sf::Vector2f(posx, posy));                                                     
        button.setFillColor(color);                                                                       
    }                                                                                                     
    void textBox(std::string ttfstring, std::string displaystring, int size, sf::Color color, int x, int y )                           
    {                                                                                                     
                                                                                                                                    
        if (!font.loadFromFile(ttfstring))                                                                
        {                                                                                                 
            printf("aint working nerd\n");                                                                
        }                                                                                                 
        textboxS.setFont(font);                                                                            
        textboxS.setString(displaystring);                                                                  
        textboxS.setCharacterSize(size);                                                                     
        textboxS.setFillColor(color);                                                                      
        textboxS.setPosition(sf::Vector2f(x, y));                            
    }                                                                       
    sf::RectangleShape getButton()                                                   
    {                                                                                
        return button;                                                               
    }                                                                     
    sf::Text gettextBox(){                                                
        return textboxS;                                                  
    }                                                                                                                                           
    bool buttonPressed(sf::Vector2i p)                                               
    {                                                                        
        size = button.getSize();                                             
        float limitx = size.x + pp.x;                                        
        float limity = size.y + pp.y;                                        
        int returnValue = 0;                                                 
        pp = button.getPosition();                                           
        if ((p.x < limitx && p.x > pp.x) && (p.y < limity && p.y > pp.y))    
        {                                                                    
           returnValue = 1;                                                 
        }                                                         
        return returnValue;                                       
          
    }                                                                                                                                           
                                                                                                                                           
private:                                                                                                                                   
    sf::Font font;                                                                                                                         
    sf::Text textboxS;                                                                                                                     
    sf::RectangleShape button;                                                                                                             
    sf::Mouse mouse;                                                                                                                       
    sf::Vector2f pp;                                                                                                                       
    sf::Vector2f size;                                                                                                                     
                                                                                                                                           
};                                                                                                                                         
      
#endif