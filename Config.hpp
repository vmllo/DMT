#include "stdio.h"                                                
#include <vector>                                                 
#include <fstream>                                                                                                                                                   
#include <iostream>                                                                                                                                                  
#include <string>          
#include "stats.hpp"                                                                                                                                                
                                                                                                                                                                     
class Config : public stats                                                                                                                                                     
{                                                                                                                                                                    
    public:                                                                                                                                                          
        void readText(std::string txt);                                                                                                                              
        int arr = 0;                                                                                                                                                 
        int header = 1;        
        std::string target[6] = {"NumberofBadguys: ", "Name: ", "Type: ", "Birthplace: ", "Armor: ", "Health: "};                                                                                                                                                                                                                                                                              
        std::string array[100];                                                                                                                                       
        std::string* parseData(std::string array[]);                                                                                                                 
                                                                                                                                                                     
};                         