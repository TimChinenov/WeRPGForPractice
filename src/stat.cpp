#include "stat.h"
#include <iostream>
/*
Stat::Stat(){
  Level=1;
  HP=5;
  mxHP=5;
  Defence=0;
  Attack_Mod=0;
  //std::cout <<"Stat constructed\n";
}
*/
Stat::~Stat(){}
Stat::Stat(int lvl,int hp,int max, int dex, int crit){
  Level=lvl;
  HP=hp;
  mxHP=max;
  Defence=dex;
  Crit=crit;
  std::cout <<"Stat constructed\n";
}
Stat Stat::operator+(Stat item_boost){
  Stat boosted;
  boosted.HP = this->HP + item_boost.HP; 
  boosted.mxHP = this->mxHP + item_boost.mxHP;
  boosted.Defence = this->Defence + item_boost.Defence;
  boosted.Crit = this->Crit + item_boost.Crit;
  return boosted;
}
Stat Stat::operator-(Stat item_boost){
  Stat boosted;
  boosted.HP = this->HP - item_boost.HP; 
  boosted.mxHP = this->mxHP - item_boost.mxHP;
  boosted.Defence = this->Defence - item_boost.Defence;
  boosted.Crit = this->Crit - item_boost.Crit;
  return boosted;
}
void Stat::getStats(){
  std::cout << "Level "<< Level << "\n";
  std::cout << "HP "<< HP << "\n";
  std::cout << "Max HP "<< mxHP << "\n";
  std::cout << "Dexterity "<< Defence << "\n";
  std::cout << "Crit Chance "<< Crit << "\n";
}
void Stat::setStat(int item_lvl,int hp_bst,int hpCap_bst,int dfn_bst, int crit){
  Level=item_lvl;
  HP=hp_bst;
  mxHP=hpCap_bst;
  Defence=dfn_bst;
  Crit=crit;
}
