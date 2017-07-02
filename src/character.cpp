#include "character.h"
#include <iostream>
#include <string>
character::character(std::string n) {//character constructor
	name = n;
	std::cout << "Your character's name is " << name <<"\n";
}
void character::dmgTaken(int damage){//damage calculation
	stats.HP = stats.HP - damage;
	std::cout << "you took " << damage << " damage.\n";
}
void character::levelUp(){
	//name^, stats increase every level. 
	Stat lvl_incr(1,3,3,2,0);
	stats + lvl_incr;
	std::cout << "You level up'd\n";
}
void character::equip(Item i){//character equip armor
	equip_stat = equip_stat + i.getStat();
}
void character::de_equip(Item i){//character removes armor
	equip_stat = equip_stat - i.getStat();
}