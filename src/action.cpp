#include "action.h"
#include "stdlib.h"
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
		int num = rand()%2;
		std::cout << "You weak hit her for " << num<< " damage\n";
		return num;
}

throwShade::throwShade(){
	name = "Shade";
}
throwShade::~throwShade(){}
int throwShade::damage(){
		int num = rand()%5;
		std::cout << "You threw shade at your enemy, way to go...\n";
		srd::cout << num << " damage\n";
		return num;
}

cast_plague::cast_plague(){
	name = "Plague";
}
cast_plague::~cast_plague(){}
int cast_plague::damage(){
		int num = rand()%4;
		std::cout << "You casted plague, you dirty animal.\n";
		std::cout << num << " damage\n";
		return num;
}

fisticuff::fisticuff(){
	name = "Fisticuff";
}
fisticuff::~fisticuff(){}
int fisticuff::damage(){
		int num = rand()%10;
		std::cout << "I see you are a person of culture, punched em in the shnoz.\n";
		std::cout << "You did " << num << " damage\n";
		return num;
}

milly_Rock::milly_Rock(){
	name = "Milly Rock";
}
milly_Rock::~milly_Rock(){}
int milly_Rock::damage(){
		int num = rand()%8;
		std::cout << "Since they can't Milly Rock on every block like yourself, enemy takes "<<num<< " damage.\n";
		return num;
}
