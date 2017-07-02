#ifndef ACTION_H
#define ACTION_H
#include <string>
#include <iostream>
class Action{
protected:
	std::string name;//name of move
public:
	virtual int damage();//default damage, unless overided
	std::string getName(){return name;}//returns name of the action
};
class weakHit:public Action{
public:
	weakHit();
	int damage();//damage() is overided, see action.cpp
	std::string getName(){return name;}
};
struct Movelist
{
	Action* actions[5];//array of 5 Action pointers represents characters "Movelist"
	Movelist(){
		actions[0] = new weakHit();//initialize weakhit as a default 
		//std::cout << "movelist created\n";
	}
};

 
#endif