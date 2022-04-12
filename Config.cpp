#include "stdio.h"
#include <fstream>
#include <iostream>
#include "Config.hpp"
#include <string>
#include <algorithm>
#define shittoprint shit
#define imlazy(shit) std::cout << shit << std::endl;
#define file "Characters_stats\\"

struct keyboard
{
    int ACII;
    std::string in;
};
struct keyboard board[200]{
    {65, "A"},
    {67, "B"},
    {68, "C"},
    {68, "D"},
    {69, "E"},
    {70, "F"},
    {71, "G"},
    {72, "H"},
    {73, "I"},
    {74, "J"},
    {75, "K"},
    {76, "L"},
    {77, "M"},
    {78, "N"},
    {79, "O"},
    {80, "P"},
    {81, "Q"},
    {82, "R"},
    {83, "S"},
    {84, "T"},
    {85, "U"},
    {86, "V"},
    {87, "W"},
    {88, "X"},
    {89, "Y"},
    {90, "Z"},
    {97, "a"},
    {98, "b"},
    {99, "c"},
    {100, "d"},
    {101, "e"},
    {102, "f"},
    {103, "g"},
    {104, "h"},
    {105, "i"},
    {106, "j"},
    {107, "k"},
    {108, "l"},
    {109, "m"},
    {110, "n"},
    {111, "o"},
    {112, "p"},
    {113, "q"},
    {114, "r"},
    {115, "s"},
    {116, "t"},
    {117, "u"},
    {118, "v"},
    {119, "w"},
    {120, "x"},
    {121, "y"},
    {122, "z"}};
bool Config::readText(std::string inputName, std::string arrays[], std::string targets[], int b, int p, int v)
{
    int didread = false;
    std::fstream newfile;
    pp = p;
    parsei = v;
    std::string inputfile = file+inputName;
    newfile.open(file+inputName, std::ios::in);
    arr = 0;
    if (newfile.is_open())
    {
        std::string tp;
        while (getline(newfile, tp))
        {
            arrays[arr] = tp;
            arr++;
        }
        didread = true;
        newfile.close();
    }
    if (b)
        parseData(arrays, targets);
    else
        r = stoi(array[0]);
    return didread;
}
void Config::configCharacters(int b)
{
    std::ofstream newfile;
    if (b)
    {
        for (int ii = 0; ii <= i; ii++)
        {
            n += dumbassKey[ii];
        }
        n = n + ".txt";
        nameArray[r] = n;
        newfile.open(file+n, std::ios::out);
        r++;

        if (newfile.is_open())
        {
            for (int ii = 0; ii <= 10; ii++)
            {
                newfile << target[ii] + array[ii] << "\n";
            }
        }
        else
        {
            std::cout << "nope" << std::endl;
        }
    }
    else
    {
        newfile.open(file"config.txt", std::ios::out);
        if (newfile.is_open())
        {

            newfile << r << "\n";
            for (int ii = 0; ii < r; ii++)
            {
                newfile << nameArray[ii] << "\n";
            }
        }
        else
        {
            std::cout << "nope" << std::endl;
        }
    }
    newfile.close();
}
void Config::ACII(unsigned int acii)
{
    for (int ii = 0; ii <= 200; ii++)
    {
        if (acii == board[ii].ACII)
        {
            dumbassKey[i] = board[ii].in;
            i++;
        }
    }
}

std::string *Config::parseData(std::string arrays[], std::string targets[])
{
    std::string my_str;
    int found = -1;
    int targeti = 0;
    int i = 0;
    targetParse = 11;
    while (parsei < 11)
    {
        if(0 == found)
            found = -1;
        my_str = arrays[parsei];
        found = my_str.find(targets[targeti], found + 1);
        if (-1 != found)
        {
            my_str = my_str.substr(0, found) + my_str.substr(found + targets[targeti].length());
            outArray[pp] = my_str;
            targeti++;
            pp++;
            i++;
        }
        parsei++;
    }

    return arrays;
}
