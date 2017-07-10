#ifndef STAT_H  // if x.h hasn't been included yet...
#define STAT_H   //   #define this so the compiler knows it has been included
#include <iostream>
class Stat{
public:
  	int Level;
  	int HP;
  	int mxHP;
	int Defence;
	int Attack_Mod;

	Stat();
	~Stat();
	Stat(int lvl,int hp,int max, int dex, int crit);
	Stat operator+(Stat b);
	Stat operator-(Stat d);
	void getStats();
<<<<<<< HEAD
=======
	void setStat(int item_lvl,int hp_bst,int hpCap_bst,int dfn_bst, int crit);
>>>>>>> a9921351fcd512c676b40fb8bdbb5741886ffae1
};

#endif 
