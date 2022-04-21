#ifndef CONFIG_HPP                                                                           
#define CONFIG_HPP                                                                           
                                                                                                                               
#include "stdio.h"                                                                                                             
#include <vector>                                                                                                              
#include <fstream>                                                                                                                                                                                                                                                                                                      
#include <iostream>                                                                                                                                                                                                                                                                                                     
#include <string>                                                                                                                                                                                                                                                                                                                                                                                                 
#include "stats.hpp"                                                                                                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                                                                                                                  
class Config                                                                                                                                                                                                                                                                                                                                                                                                      
{                                                                                                                                                                                                                                                                                                                                                                                                                 
    public:                                                                                                                                                                                                                                                                                                                                                                                                       
        bool readText(std::string file, std::string txt,std::string arrays[],std::string targets[], int b, int p, int v, int invb);                                                                                                                                                                                                                                                                                                                                                      
        int arr = 0;                                                                                                                                                                                                                                                                                                                                                                                              
        int header = 1;                                                                                                                                                                                                                                                                                                                                                                                           
        std::string target[12] = {"Name: ", "Type: ", "Birthplace: ", "Armor: ", "Health: ", "STR: ","DEX: ","CON: ", "INT: ", "WIS: ", "CHA: ", "INV: "};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        void configCharacters(std::string file, int b);    
        void ACII(unsigned int acii);                                                                                                                                                                                                                                                                                                                                                                                                             
        std::string* parseData(std::string array[], std::string target[]);    
        void init(int creatxx, int donexx, int loadxx, int loadexx, int configxx, int invxx, int creatyy, int doneyy, int loadyy, int loadeyy, int configyy, int invyy);                                                                                                                                                                                                                                                                                                                                                          
        int targetParse;       
        int i;
        int pp;
        std::string n; 
        char configBool;     
        int r = 0;
        int parsei = 0;
        int rr = 0;
        std::string dumbass;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
        std::string array[100];   
        std::string outArray[100];
        std::string dumbassKey[100];
        std::string arrayInv[300];
        std::string nameArray[100];
        int creatx;
        int donex;
        int loadx;
        int loadex;
        int configx;
        int invx;
        int creaty;
        int doney;
        int loady;
        int loadey;
        int configy;
        int invy;
        enum GUIstate
        {
            createState,
            doneState,
            invState,
            configState
        };
        GUIstate states;
};                                                                                                                                                                                                                                                                                                                                                                                                                
#endif                                                                                                                                                                                                                                                                                                                                                                                                            