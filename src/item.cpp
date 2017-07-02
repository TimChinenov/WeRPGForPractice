#include "item.h"
#include <iostream>
#include <string>
Item::Item(){
	//this is an abstract class, so if there is an item that is constructed
	//it will be unidentified, and you'll know you initialized such an item.
	name = "unidentified";
	std::cout << "what is this?\n";
}
Item::Item(std::string n){//need to add stats to Constuctor
	//this constructor is for basic armor.
	name = n;
	std::cout << "The name of this item is " << name << "\n";
}
Stat Item::getStat(){
	return boost;//just returns the stats of the item
}