#include "stat.h"
#include <iostream>
Stat::Stat(){
  //Default stats
  Level=1;
  HP=5;
  mxHP=5;
  Defence=0;
  Attack_Mod=0;
  //std::cout <<"Stat constructed\n";
}
Stat::Stat(int lvl,int hp,int max, int dex, int crit){
  //Stat constructor for loading from save point or giving an item specific stats
  Level=lvl;
  HP=hp;
  mxHP=max;
  Defence=dex;
  Attack_Mod=crit;
  std::cout <<"Stat constructed\n";
}
Stat Stat::operator+(Stat item_boost){
  //operator to adding stats
  Stat boosted;
  boosted.HP = this->HP + item_boost.HP; 
  boosted.mxHP = this->mxHP + item_boost.mxHP;
  boosted.Defence = this->Defence + item_boost.Defence;
  boosted.Attack_Mod = this->Attack_Mod + item_boost.Attack_Mod;
  return boosted;
}
Stat Stat::operator-(Stat item_boost){
  //operator for subtracting stats, if for example a move effect from an enemy decreases defence or max HP. 
  Stat boosted;
  boosted.HP = this->HP - item_boost.HP; 
  boosted.mxHP = this->mxHP - item_boost.mxHP;
  boosted.Defence = this->Defence - item_boost.Defence;
  boosted.Attack_Mod = this->Attack_Mod - item_boost.Attack_Mod;
  return boosted;
}
void Stat::getStats(){
  //just returns current stats.
	std::cout << "Level "<< Level << "\n";
	std::cout << "HP "<< HP << "\n";
	std::cout << "Max HP "<< mxHP << "\n";
	std::cout << "Dexterity "<< Defence << "\n";
	std::cout << "Crit Chance "<< Attack_Mod << "\n";
}