#ifndef STATS_HPP
#define STATS_HPP
                 
#include <string>
                 
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
    void setMods(std::string mods)                                               
    {                                                                            
        int found = mods.find(",");                                              
        int flag = 1;                                                            
        int i = 1;                                                               
        int ii = 0;                                                              
        if(found != -1)                                                          
        {                                                                                                                                            
           // mods.insert(found, "\n");                                            
            std::cout << mods << std::endl;                                      
        }                                                                        
        this->mods = mods;                                                       
    }                                     
    void setInv(std::string inv){         
        this->inv = inv;                  
    }                                                                          
    std::string getLocation()                                                    
    {                                                                            
        return location;                                                         
    }                                     
    std::string getInv(){                 
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
    std::string getMods()                                                        
    {                                                                            
        return mods;                                                             
    }                                                                            
                                                              
protected:                                            
    std::string health;
    std::string armor;
    std::string type;
    std::string name;
    std::string location;
    std::string mods;
    std::string inv;
};                   
class Creature : public stats
{                    
public:              
    void defaultCreature(std::string health, std::string armor, std::string type, std::string name, std::string location)
    {                
        stats::health = health;
        stats::armor = armor;
        stats::location = location;
        stats::type = type;
        stats::name = name;
    } 
};    
      
#endif