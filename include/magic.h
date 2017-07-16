#ifndef SPELL_H
#define SPELL_H

//C Includes



//C++ Includes
#include <climits>
#include <string>
#include <vector>


//Custom Includes
#include "character.h"


//Temporary Includes



class Magic{
 private:
  character* caster;
  unsigned int level_req;
  std::string spell_name;
  std::string effect_desc;
  std::string failure_desc;
 public:
  
  Magic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc){this->caster = caster; this->level_req = level_req; this->effect_desc = effect_desc; this->failure_desc = failure_desc;};
  
 Magic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc)
   :Magic(caster, level_req, spell_name, effect_desc,  "Ancients whispers through time and space, disappating your spell"){};

 Magic()
   :Magic(NULL, UINT_MAX, "Unknown Spell", "Reality refused to be altered, this spell has failed",  "Ancients whispers through time and space, disappating your spell"){};

 virtual void becast() = 0;
 
};

//Intended use of the spell

class CombatMagic:public virtual Magic{
 private:
  unsigned int damage;
 public:
  
 CombatMagic()
   :Magic(){this->damage = 0;};
  
 CombatMagic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc, unsigned int damage)
   :Magic(caster, level_req, spell_name, effect_desc, failure_desc){this->damage = damage;};
  
 CombatMagic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc, unsigned int damage)
   :CombatMagic(caster, level_req, spell_name, effect_desc, "Ancients whispers through time and space, disappating your spell", damage){};
};

class UtilityMagic:public virtual Magic{
 private:

 public:

  
};

//Targeting of spells

template<class T>
class TargetedMagic:public virtual Magic{  
 public:
  virtual std::string cast(unsigned int level, std::vector<T*> targets) = 0;

};


//Payment for spells

class SacrificialMagic:public virtual Magic{
 private:
  unsigned int cost;
 public:

 SacrificialMagic()
   :Magic(){this->cost = UINT_MAX;};

 SacrificialMagic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc, std::string failure_desc, unsigned int cost)
   :Magic(caster, level_req, spell_name, effect_desc, failure_desc){this->cost = cost;};

 SacrificialMagic(character *caster, unsigned int level_req, std::string spell_name, std::string effect_desc, unsigned int cost)
   :Magic(caster, level_req, spell_name, effect_desc){this->cost = cost;};
  
};

class BloodBorneMagic:public virtual SacrificialMagic{

};

class ManaBorneMagic:public virtual SacrificialMagic{

};

class WealthBorneMagic:public virtual SacrificialMagic{

};

class TimeBorneMagic:public virtual SacrificialMagic{

};


#endif
