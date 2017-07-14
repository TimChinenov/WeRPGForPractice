#ifndef STAT_H  // if x.h hasn't been included yet...
#define STAT_H   //   #define this so the compiler knows it has been included
#include <iostream>

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
