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
 character():character(""){};
  character(std::string n);
  virtual ~character();
  int attack(Action* move);//Damage given
  void dmgTaken(int damage);//Damage taken
  void equip(Item i);//Equip Item
  void exchange(Item i);//Switch with existing item
  void dequip(int item_slot);//Remove item from equipment
  std::string getName();
};
class Hero : public character{
protected:
  int expr;//experience
  int expr_cap;//experience cap
public:
  Hero(std::string n);
  ~Hero();
  void exp_update(int gain);//calculates exp gain
  void levelUp();//<- self explanitory

};
class Ghoul : public character{
protected:
  int expr;
public:
  Ghoul();
  Ghoul(int level);
  ~Ghoul();
};

#endif
