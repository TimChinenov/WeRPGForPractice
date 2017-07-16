#ifndef ACTION_H
#define ACTION_H
#include <string>
#include <iostream>

class Action{
protected:
	std::string name;
public:
	virtual ~Action();
	virtual int damage()=0;
	virtual std::string getName()=0;
};

class weakHit:public Action{
public:
	weakHit();
	~weakHit();
	int damage();
	std::string getName(){return name;}
};
class throwShade:public Action{
public:
	throwShade();
	~throwShade();
	int damage();
	std::string getName(){return name;}
};
class cast_plague:public Action{
public:
	//damage over time, let's make that happen
	cast_plague();
	~cast_plague();
	int damage();
	std::string getName(){return name;}
};
class fisticuff:public Action{
public:
	fisticuff();
	~fisticuff();
	int damage();
	std::string getName(){return name;}
};
class milly_Rock:public Action{
public:
	milly_Rock();
	~milly_Rock();
	int damage();
	std::string getName(){return name;}
};
struct Movelist
{
	Action* actions[5];
	Movelist(){
		actions[0] = new weakHit();
	}
};


#endif
