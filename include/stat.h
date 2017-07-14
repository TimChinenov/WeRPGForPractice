#ifndef STAT_H  // if x.h hasn't been included yet...
#define STAT_H   //   #define this so the compiler knows it has been included
#include <iostream>

/*
So basically stats are broken down into 2 forms, stats for
characters and stats for items. They are essentially the same
class, but will be used somewhat differently. The level on
items will be a sort of glass cieling, preventing characters
that aren't at or above the level of the item to use it.
The rest are used to add something to the character's stats.
Been meaning to redo stats though, I feel like I focused too
much on defence without thinking about offensive stats.
*/

class Stat{
 public:
  	int Level;
  	int HP;
  	int mxHP;
	int Defence;
	int Crit;
        Stat():Stat(1, 5, 5, 0, 0){};
	~Stat();
	Stat(int lvl,int hp,int max, int dex, int crit);
	Stat operator+(Stat b);
	Stat operator-(Stat d);
	void getStats();
	void setStat(int item_lvl,int hp_bst,int hpCap_bst,int dfn_bst, int crit);
};

#endif
