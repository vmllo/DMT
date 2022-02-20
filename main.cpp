#include "GUI.hpp"                                                         
#include "Config.hpp"                                                      
#include <cmath>                                                                
#include <string>                                                               
#include "stats.hpp"                                                            
                                                                                
int main()                                                                      
{                                                                               
    int spot;                                                                   
    GUI button[7];                                                              
    GUI invButton[1];                                                           
    GUI textbox[7];                                                                                                                        
    int flag = 1;                                                                        
    sf::Vector2i p;                                                             
    GUI playerBox[5];                                                           
    int pos[7] = {150, 250, 350, 450, 550, 650, 750};                                           
    Config con;                                                                                 
    con.targetParse = 7;                                                                        
    con.readText("config.txt", con.array, con.target);                                          
    con.targetParse = 4;                                                                        
    con.readText("inventory.txt",con.arrayInv,con.invarr);                                      
    const int arraySize2 = stoi(con.array[0]);                                                  
    const int invsize = stoi(con.arrayInv[0]);                                                  
    Creature m[arraySize2];                                                                     
    Creature inv[100];                                                                          
    int ii = 1;                                                                                                                                         
    for (int i = 0; i <= arraySize2 - 1; i++)                                                   
    {                                                                                                                                                                            
        m[i].setName(con.array[ii++]);                                                            
        m[i].setType(con.array[ii++]);                                                          
        m[i].setLocation(con.array[ii++]);                                                      
        m[i].setarmor(con.array[ii++]);                                                         
        m[i].setHealth(con.array[ii++]);                                                        
        m[i].setMods(con.array[ii++]);                                                                                                       
    }                                              
    for (int i = 1; i <= 30; i++)                                                   
    {                                                                                                                                                                            
        con.configCharacters(i, con.array[i]);                                                                                                       
    }                                              
                                                                                       
    //ii = 1;                                                                                     
    //for(int i = 0; i <= invsize-1;i++){                                                       
        //  inv[i].setInv(con.arrayInv[ii++]);                                                                              
    //}                                                                                                               
                                                                                          
    sf::RectangleShape background;                                                            
    background.setFillColor(sf::Color::Black);                                                
    background.setSize(sf::Vector2f(1000, 1000));                                             
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Demo Tool");                          
    for (int i = 0; i <= arraySize2 - 1; i++)                                                 
    {                                                                                         
        textbox[i].textBox("ArialCE.ttf", m[i].getName(), 24, sf::Color::Red, pos[i], 60);    
    }                                                                                         
    for(int i = 0; i <= 4;i++){                                                              
       std::cout << inv[i].getInv() << std::endl;                                             
                                                                                                                 
    }                                                                                         
    for (int i = 0; i <= arraySize2 - 1; i++)                                                 
    {                                                                                         
        button[i].setButton(75, 50, pos[i], 60, sf::Color::White);                            
    }                                                                                                                                                                                                                      
    while (window.isOpen())                                                                                                  
    {                                                                                                                        
        sf::Event event;                                                                                                     
        while (window.pollEvent(event))                                                                                      
        {                                                                                                                    
            if (event.type == sf::Event::MouseButtonPressed)                                                                 
            {                                                                                                                
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))                                                                                                                                                                                                                                               
                {                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                 
                    p = sf::Mouse::getPosition(window);                                                                                                                                                                                                                                                          
                    for (int i = 0; i <= arraySize2 - 1; i++)                                                                                                                                                                                                                                                    
                    {                                                                                                                                                                                                                                                                                            
                        spot = i;                                                                                                                                                                                                                                                                                
                        if (button[i].buttonPressed(p))                                                                                                                                                                                                                                                          
                        {                                                                                                                                                                                                                                                                                        
                            playerBox[0].textBox("ArialCE.ttf", "Birthplace\n" + m[spot].getLocation() + "\n\nHP\n" + m[spot].getHealth() + "\n\nAC\n" + m[spot].getarmor(), 24, sf::Color::Red, 150, 200);                                                                                                      
                            playerBox[1].textBox("ArialCE.ttf", "Class\n" + m[spot].getType() + "\n\nStats\n" + m[spot].getMods(), 24, sf::Color::Red, 550, 200);                                                                                                                                                
                                                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                                                 
                            for (int i = 0; i <= 2; i++)                                                                                                                                                                                                                                                         
                            {                                                                                                                                                                                                                                                                                    
                                window.draw(playerBox[i].gettextBox());                                                                                                                                                                                                                                          
                            }                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                 
                            window.display();                                                                                                                                                                                                                                                                    
                        }                                                                                                                                                                                                                                                                                        
                    }                                                                                                                                                                                                                                                                                            
                }                                                                                                                                   
            }                                                                                                                                       
            if (event.type == sf::Event::Closed)                                                                                                    
            {                                                                                                                                       
                printf("noob");                                                                                                                     
                window.close();                                                                                                                     
            }                                                                                                                     
                                                                                                                                  
            window.clear();                                                                                                       
            window.draw(background);                                                                                              
            for (int i = 0; i <= arraySize2 - 1; i++)                                                                             
            {                                                                               
                window.draw(button[i].getButton());                                         
            }                                                                               
            for (int i = 0; i <= 7; i++)                                                    
            {                                                                               
                window.draw(textbox[i].gettextBox());                       
            }                                                
            if (flag)                                        
            {                                        
                window.display();                    
                flag = 0;                      
            }                                  
        }                                      
    }                                          
                                               
    return 0;                                  
}                                              
                                               