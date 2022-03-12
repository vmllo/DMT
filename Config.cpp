#include "stdio.h"                                                                                                                             
#include <fstream>                                                                                                                                                                                  
#include <iostream>                                                                                                                                                                                 
#include "Config.hpp"                                                                                                                                                                               
#include <string>                                                                                                                                                                                   
#include<algorithm>                                                                                                                                                                                 
                                                                                                                                                                                                    
void Config::readText(std::string inputName, std::string arrays[], std::string targets[]){                                                                                                                          
   std::fstream newfile;                                                                                                                                                                            
   newfile.open(inputName, std::ios::in);                                                                                                                                                           
   arr = 0;                                                                                                                                                       
   if(newfile.is_open()){                                                                                                                                                                           
       std::string tp;                                                                                                                                                                              
       while(getline(newfile,tp)){                                                                                                                                                                              
            arrays[arr] = tp;                                                                                                                                                                       
            arr++;                                                                                                                                                                                                  
       }                                                                                                                                                                                            
       newfile.close();                                                                                                                                                                             
   }                                                                                                                                                                                                                                                                                                                       
   parseData(arrays, targets);                                                                                                                                                                      
}                                                                                                                             
 void Config::configCharacters(int ii, std::string arrays)                                                                            
 {                                                                                                                            
    std::ofstream newfile;                                                                                                    
    std::string name = arrays;                                                                                                
    std::cout << name << std::endl;                                                                                           
    newfile.open(arrays);                                                                                                                
    if (newfile.is_open())                                                                                           
    {                                                                                                                
        for (ii; ii <= 6; ii++)                                                                                      
        {                                                                                                            
            newfile << array[ii] + "\n";                                                                              
        }                                                                                                            
    }                                                                                                                
    else                                                                                                             
    {                                                                                                                
        std::cout << "nope" << std::endl;                                                                            
    }                                                                                                                
 }                                                                                                                                                                                                                                                                                                                                                                                                                   
                                                                                                                                                                       
std::string* Config::parseData(std::string arrays[], std::string targets[])                                                                                                                    
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
            my_str = arrays[parsei];                                                                          
            found = my_str.find(targets[targeti], found + 1);                                                                           
            if (found != -1)                                                                                  
            {                                                                                      
                my_str = my_str.substr(0, found) + my_str.substr(found + targets[targeti].length());                                                                       
                arrays[parsei] = my_str;                                                            
                parsei++;                                                                          
                targeti++;                                                                         
                if(targeti == targetParse){                                                                  
                    targeti = 1;                                                                   
                }                                                                                  
            }                                                                                      
        }                                                                                          
    }while (found != -1);                                                                                           
    return arrays;                                                                                  
}                                                                                                  
                                                                                                   