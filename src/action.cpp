#include "action.h"
#include <iostream>
#include <string>
int Action::damage(){
  //pure virtual function
  return 0;
}
Action::~Action(){}

weakHit::~weakHit(){}
weakHit::weakHit(){
	name = "weakhit";
}
int weakHit::damage(){
		std::cout << "You weak hit her for 2 damage\n";
		return 2;
}

throwShade::throwShade(){
	name = "Shade";
}
throwShade::~throwShade(){}
int throwShade::damage(){
		std::cout << "You threw shade at your enemy, way to go...\n";
		return 5;
}

cast_plague::cast_plague(){
	name = "Plague";
}
cast_plague::~cast_plague(){}
int cast_plague::damage(){
		std::cout << "You casted plague, you dirty animal.\n";
		return 4;
}

fisticuff::fisticuff(){
	name = "Fisticuff";
}
fisticuff::~fisticuff(){}
int fisticuff::damage(){
		std::cout << "I see you are a person of culture, punched em in the shnoz for 10 damage\n";
		return 10;
}

milly_Rock::milly_Rock(){
	name = "Milly Rock";
}
milly_Rock::~milly_Rock(){}
int milly_Rock::damage(){
		std::cout << "Since they can't Milly Rock on every block like yourself, enemy takes 8 damage.\n";
		return 8;
}
