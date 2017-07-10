#ifndef ITEM_H   // if x.h hasn't been included yet...
#define ITEM_H   //   #define this so the compiler knows it has been included
#include "stat.h"
#include <string>
/*
	So this header file is mostly dedicated to the Item base class
	and it's associating derived classes. Just a bunch of Constructor
	and Destructors so nothing fancy.
*/
class Item{
protected:
  std::string name;
  Stat boost;
public:
    Item();
    virtual ~Item();
	Item(std::string name);
	Stat getStat();
	std::string getName();
};
class c_ring:public Item{
	c_ring(); 
	~c_ring();                                                                                                                                                                                                                                                                                                                                                                                      
};                                                                                                                                                                                                                                                                                                                                             
class tea:public Item{
	tea();
	~tea();
};
class Keybrd_SJW:public Item{
	Keybrd_SJW();
	~Keybrd_SJW();
};
class SOMB:public Item{
	SOMB();
	~SOMB();
};
class Black_Beanie:public Item{
	Black_Beanie();
	~Black_Beanie();
};
//this on the other hand is the structure for the Character Equipment
struct Equipment
{
		Item* equips[5];//Pointers that act as the list of items
		bool has_item[5];//array of booleans to keep track of which slot is filled or not
		Equipment(){
			for(int i=0;i<5;i++) has_item[i] = false;//just set all slots empty in the constructor
	}
};

#endif
