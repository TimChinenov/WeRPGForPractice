#ifndef CHARACTER_H   // if x.h hasn't been included yet...
#define CHARACTER_H   //   #define this so the compiler knows it has been included
#include "stat.h"
#include "item.h"
#include "action.h"
#include <string>
#include <iostream>
class character{
protected:
  std::string name;//name of character
  Stat stats;//base stats
  Stat equip_stat;//stats from equipment
  Equipment eq;//list of equipment
  Movelist moves;//list of moves
public: 
  character(std::string n);
  void dmgTaken(int damage);//damage calculation
  void updateStats();//update stats when equipment is put on/taken off
  void equip(Item i);//<- says it
  void de_equip(Item i);//<- "  "
  void levelUp();//changes base stats after leveling up
};

#endif 