#ifndef STAT_H  // if x.h hasn't been included yet...
#define STAT_H   //   #define this so the compiler knows it has been included
#include <iostream>

class Stat{
  public:
    int Level;
    int HP;//current health
    int mxHP;//health cap
    int Defence;//if the attack from the enemy does not surpass the defence of the attacke, the move does no damage
    int Attack_Mod;//crit chance

  	Stat();
  	Stat(int lvl,int hp,int max, int dex, int crit);
  	Stat operator+(Stat b);
  	Stat operator-(Stat d);
  	void getStats();
};

#endif
