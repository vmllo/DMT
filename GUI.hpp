                                                                                     
#include <SFML/Graphics.hpp>                                                         
                                                                                     
class GUI: public stat                                                               
{                                                                                    
public:                                                                              
    void setButton(float sizex, float sizey, float posx, float posy, sf::Color color)
    {                                                                                
        button.setSize(sf::Vector2f(sizex, sizey));                                  
        button.setPosition(sf::Vector2f(posx, posy));                                
        button.setFillColor(color);                                                  
    }                                                                                
    sf::RectangleShape getButton()                                                   
    {                                                                                
        return button;                                                               
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
    sf::RectangleShape button;                     
    sf::Mouse mouse;                               
    sf::Vector2f pp;                               
    sf::Vector2f size;     
                           
};                         
                           