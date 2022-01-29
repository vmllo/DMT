#include "GUI.hpp"  
#include "Config.hpp"   
#include <cmath>        
#include <string>         
#include "stats.hpp"            
                                      
/*                                          
Creature* setCreature(){                    
    Config con;                              
    con.readText("config.txt");              
    const int arraySize2 = stoi(con.array[0]);
    int ii = 1;                              
   for(int i = 0; i <= arraySize2-1;i++){    
       m[i].setName(con.array[ii++]);        
       m[i].setType(con.array[ii++]);        
       m[i].setLocation(con.array[ii++]);    
       m[i].setarmor(stoi(con.array[ii++])); 
       m[i].setHealth(stoi(con.array[ii++]));
   }                                         
                                             
  return m;                                  
}                                            
  */                                         
                                             
int main()                                   
{                                            
    Config con;                                                     
    GUI button[2];                                                   
    GUI textbox[2];                                                  
    button[0].setButton(200, 100, 600, 200, sf::Color::Red);                       
    button[1].setButton(200, 100, 100, 200, sf::Color::Red);                          
                                                                                      
    sf::RectangleShape background;                                                    
    background.setFillColor(sf::Color::Black);                                        
    background.setSize(sf::Vector2f(1000, 1000));                                     
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Demo Tool");                  
                                                                                      
                                                                                      
    textbox[0].textBox("ArialCE.ttf", "penis head",24,sf::Color::Red, 120,60);        
    textbox[1].textBox("ArialCE.ttf", "penis head2",24,sf::Color::Red, 240,60);       
                                                                                      
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
                    if (button[0].buttonPressed(p))                          
                    {                                                        
                        printf("penis1\n");                                 
                    }                                               
                    else if (button[1].buttonPressed(p))            
                    {                                               
                        printf("penis2\n");                       
                    }                                             
                                                                  
                    printf("%d\n%d\n", p.x, p.y);       
                }                                       
                if (event.type == sf::Event::Closed)    
                {                                       
                    window.close();                     
                }                                       
            }                                           
        }                                               
        window.clear();               
        window.draw(background);                                 
        window.draw(textbox[0].gettextBox());           
        window.draw(textbox[1].gettextBox());                
                                                        
                                      
                                                        
        for (int i = 0; i <= 1; i++)                    
        {                                               
            window.draw(button[i].getButton());         
        }                                               
                                                        
        window.display();                               
    }                                                   
                                                        
    return 0;                                           
}                                                       
                             