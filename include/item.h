#ifndef ITEM_H   // if x.h hasn't been included yet...
#define ITEM_H   //   #define this so the compiler knows it has been included
#include "stat.h"
#include <string>
class Item{
protected:
  std::string name;//name of item
  Stat boost;//item stats
public:
    Item();
	Item(std::string name);
	Stat getStat();
};
struct Equipment
{
		Item* equips[5];//5 pointers that denote the list of equipment the character has on.
};

#endif
