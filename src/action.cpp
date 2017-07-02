#include "action.h"
#include <iostream>
#include <string>
int Action::damage(){
	//default attack  is a screech that does 1 damage
	std::cout <<"You yelled at them for 1 damage\n";
 return 1;
}
weakHit::weakHit(){
	name = "weakhit";
}
int weakHit::damage(){
	//similar to pound/tackle, all character will be given the move weak hit
		std::cout << "You weak hit her for 2 damage\n";
		return 2;
}