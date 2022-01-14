#include <string>

class stats
{
public:
    int getHealth()
    {
        return health;
    }

    void setHealth(int health)
    {
        this->health = health;
    }
    int getarmor()
    {
        return armor;
    }

    void setarmor(int armor)
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
    std::string getName()
    {
        return name;
    }
    std::string getType()
    {
        return type;
    }    
         
protected:
    int health;
    int armor;
    std::string type;
    std::string name;
    std::string location;
};       
class Creature : public stats
{        
public:  
    void defaultCreature(int health, int armor, std::string type, std::string name, std::string location)
    {    
        stats::health = health;
        stats::armor = armor;
        stats::location = location;
        stats::type = type;
        stats::name = name;
    }    
};