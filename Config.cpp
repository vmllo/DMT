#include "stdio.h"                                                                                      
#include <fstream>                                                                                                  
#include <iostream>                                                                                                 
#include "Config.hpp"                                                                                               
#include <string>                                                                                                   
                                                                                                                                              
                                                                                                                                                                       
void Config::readText(std::string inputName){                                                                                                                          
   std::fstream newfile;                                                                                                                                               
   newfile.open(inputName, std::ios::in);                                                                                                                              
                                                                                                                                                                       
   if(newfile.is_open()){                                                                                                                                              
       std::string tp;                                                                                                                                                 
       while(getline(newfile,tp)){                                                                                                                                     
            array[arr] = tp;                                                                                                                                           
            arr++;                                                                                                                                                                                                  
       }                                           
       newfile.close();                                                                                                                                                
   }                                                                                                                                                                   
    parseData(array);                                                                                                                                                                                                                                                              
}                                                                                                                                                                      
                                                                                                                                                                       
std::string* Config::parseData(std::string array[])                                                                                                                    
{                                                                                                                                                                      
    std::string my_str;                                                                                                                                                
    int found = -1;                                                                                                                                                  
    int targeti = 0;                                                                                            
    int parsei = 0;                                                                                        
    do                                                                                                                                                               
    {                                                                                                     
        found = -1;                                                                                       
        if (parsei < (arr))                                                                         
        {                                                                                      
            my_str = array[parsei];                                                                 
            found = my_str.find(target[targeti], found + 1);                                                                           
            if (found != -1)                                                                   
            {                                                                                 
                my_str = my_str.substr(0, found) + my_str.substr(found + target[targeti].length());                                                                       
                array[parsei] = my_str;                                                           
                parsei++;                                                                    
                targeti++;                                                                         
                if(targeti == 6){                                                                  
                    targeti = 1;                                                                   
                }                                                                            
            }                                                                                
        }                                                                                    
    }while (found != -1);                                                                                           
    return array;                                                                            
}                                                               
