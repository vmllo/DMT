#ifndef CONFIG_HPP
#define CONFIG_HPP
                  
#include "stdio.h"                                                
#include <vector>                                                 
#include <fstream>                                                                                                                                                   
#include <iostream>                                                                                                                                                  
#include <string>                                                                                                                
                                                                                                                                 
                                                                                                                                 
class Config                                                                                                                                                  
{                                                                                                                                                                    
    public:                                                                                                                                                          
        void readText(std::string txt);                                                                                                                              
        int arr = 0;                                                                                                                                                 
        int header = 1;                                                                                                          
        std::string target[8] = {"NumberofPlayers: ", "Name: ", "Type: ", "Birthplace: ", "Armor: ", "Health: ", "Mods: ", "Inv: "};                                                                                                                                                                                                                                                                              
        std::string array[100];                                                                                                                                       
        std::string* parseData(std::string array[]);                                                                                                                 
                                                                                                                                                                     
};    
#endif                                                                                                                             