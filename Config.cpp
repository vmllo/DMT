#include "stdio.h"
#include <fstream>
#include <iostream>
#include "Config.hpp"
#include <string>
#include <algorithm>
#define shittoprint shit
#define imlazy(shit) std::cout << shit << std::endl;

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
    {122, "z"}
};
void Config::readText(std::string inputName, std::string arrays[], std::string targets[])
{
    std::fstream newfile;
    newfile.open(inputName, std::ios::in);
    arr = 0;
    if (newfile.is_open())
    {
        std::string tp;
        while (getline(newfile, tp))
        {
            arrays[arr] = tp;
            arr++;
        }
        newfile.close();
    }
    parseData(arrays, targets);
}
void Config::configCharacters()
{
    std::ofstream newfile;
    for (int ii = 0; ii <= i; ii++)
    {
        n += dumbassKey[ii];
    }
    n = n + ".txt";
    nameArray[r] = n;
    r++;
    imlazy(r);
    newfile.open(n, std::ios::out);
    std::cout << n << std::endl;
    if (newfile.is_open())
    {
        for (int ii = 0; ii <= 6; ii++)
        {
            newfile << target[ii] + array[ii];
        }
    }
    else
    {
        std::cout << "nope" << std::endl;
    }
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
                if (targeti == targetParse)
                {
                    targeti = 1;
                }
            }
        }
    } while (found != -1);
    return arrays;
}
