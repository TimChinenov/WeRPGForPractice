#include "item.h"
#include <iostream>
#include <string>
Item::Item(){//base Item constructor.
	name = "unidentified";//just in case, you know?
}
Item::~Item(){}
Item::Item(std::string n){//
	name = n;
	std::cout << "The name of this item is " << name << "\n";
}
Stat Item::getStat(){
	return boost;
}
std::string Item::getName(){ return name;}
c_ring::c_ring(): Item("C-Ring"){//I'm not sure if I should be proud of this..
	boost.setStat(1,1,1,1,1);
	std::cout << "I wonder why my wife isn't picking up her phone?\n";
}
c_ring::~c_ring(){}
tea::tea(): Item("Tea of the Frog"){
	boost.setStat(1,2,2,0,0);
}
tea::~tea(){}
Keybrd_SJW::Keybrd_SJW(): Item("Keyboard of the SJW"){
	boost.setStat(1,5,5,2,0);
}
Keybrd_SJW::~Keybrd_SJW(){}
SOMB::SOMB(): Item("Strap-on Man Bun"){
	boost.setStat(1,10,0,0,0);
}
SOMB::~SOMB(){}
Black_Beanie::Black_Beanie(): Item("Beanie of the Void"){
	boost.setStat(1,0,0,10,0);
}
Black_Beanie::~Black_Beanie(){}