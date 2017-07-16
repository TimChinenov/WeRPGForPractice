#ifndef SPELL_H
#define SPELL_H

//C Includes



//C++ Includes
#include <climits>
#include <string>
#include <vector>


//Custom Includes



//Temporary Includes



class Magic{
 private:
  unsigned int level_req;
  std::string spell_name;
  std::string effect_desc;
  std::string failure_desc;
 public:
  
 Magic(unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc){this->level_req = level_req; this->effect_desc = effect_desc; this->failure_desc = failure_desc;};
  
 Magic(unsigned int level_req, std::string spell_name, std::string effect_desc)
   :Magic(level_req, spell_name, effect_desc,  "Ancients whispers through time and space, disappating your spell"){};

 Magic()
   :Magic(UINT_MAX, "Unknown Spell", "Reality refused to be altered, this spell has failed",  "Ancients whispers through time and space, disappating your spell"){};

 virtual std::string cast(unsigned int level);
};

//Intended use of the spell

class CombatMagic:public virtual Magic{
 private:
  unsigned int damage;
 public:
  
 CombatMagic()
   :Magic(){this->damage = 0;};
  
 CombatMagic(unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc, unsigned int damage)
   :Magic(level_req, spell_name, effect_desc, failure_desc){this->damage = damage;};
  
 CombatMagic(unsigned int level_req, std::string spell_name, std::string effect_desc, unsigned int damage)
   :CombatMagic(level_req, spell_name, effect_desc, "Ancients whispers through time and space, disappating your spell", damage){};
};

class UtilityMagic:public virtual Magic{
 private:

 public:

  
};

//Targetting of spells

template<class T>
class TargetedMagic:public virtual Magic{  
 public:
  
  
};


//Payment for spells

class SacrificialMagic:public virtual Magic{
 private:
  unsigned int cost;
 public:

 SacrificialMagic()
   :Magic(){this->cost = UINT_MAX;};

 SacrificialMagic(unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc, unsigned int cost)
   :Magic(level_req, spell_name, effect_desc, failure_desc){this->cost = cost;};

 SacrificialMagic(unsigned int level_req, std::string spell_name, std::string effect_desc, unsigned int cost)
   :Magic(level_req, spell_name, effect_desc){this->cost = cost;};
  
};



#endif
