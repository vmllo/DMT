#ifndef STATS_HPP
#define STATS_HPP

#include <string>
#include "Config.hpp"

class stats
{
public:
    std::string getHealth()
    {
        return health;
    }

    void setHealth(std::string health)
    {
        this->health = health;
    }
    std::string getarmor()
    {
        return armor;
    }

    void setarmor(std::string armor)
    {
        this->armor = armor;
    }
    void setType(std::string type)
    {
        this->type = type;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setLocation(std::string location)
    {
        this->location = location;
    }
     void setStr(std::string str)
    {
        this->str = str;
    }
     void setDex(std::string dex)
    {
        this->dex = dex;
    }
     void setCon(std::string con)
    {
        this->con = con;
    }
     void setInt(std::string inti)
    {
        this->inti = inti;
    }
     void setWis(std::string wis)
    {
        this->wis = wis;
    }
     void setCha(std::string cha)
    {
        this->cha = cha;
    }
    void setInv(std::string inv)
    {
        this->inv = inv;
    }
    std::string getLocation()
    {
        return location;
    }
    std::string getInv()
    {
        return inv;
    }
    std::string getName()
    {
        return name;
    }
    std::string getType()
    {
        return type;
    }
    std::string getStr()
    {
        return str;
    }
    std::string getDex()
    {
        return dex;
    }
    std::string getCon()
    {
        return con;
    }
    std::string getInti()
    {
        return inti;
    }
     std::string getWis()
    {
        return wis;
    }
    std::string getCha()
    {
        return cha;
    }

protected:                                                    
    std::string health;                                       
    std::string armor;                                        
    std::string type;
    std::string name;
    std::string location;
    std::string str;
    std::string dex;
    std::string con;
    std::string inti;
    std::string wis;
    std::string cha;
    std::string inv;
};
class Creature : public stats
{                    
public:              
    void defaultCreature(std::string health, std::string armor, std::string type,std::string name, std::string location)
    {                
        stats::health = health;
        stats::armor = armor;
        stats::location = location;
        stats::type = type;
        stats::name = name;
    } 
};    
      
#endif