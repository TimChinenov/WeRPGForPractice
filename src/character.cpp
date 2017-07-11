#include "character.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
character::character(std::string n) {//character base constructor
	name = n;
	std::cout << "Your character's name is " << name <<"\n";
}
character::~character(){}//base destructor
int character::attack(Action* move){//function to initiate attack move
	int crit_dmg = 0;
	srand(time(NULL));//get's random seed
	int chance = this->equip_stat.Attack_Mod + this->stats.Attack_Mod;
	for(int i=0;i<chance;i++){//the each point in Attack Mod is another chance to crit
		int random = rand()%20 +1; //picks a number from 1-20
		if(random>15) crit_dmg += move->damage() / 4;//if it's 16 or above, it crits
	}
	int total_dmg = move->damage() + crit_dmg;//move damage plus crit damage
	return total_dmg;
}
void character::dmgTaken(int damage){//function to calculate damage taken
	/*	if the damage recieved is not greater than the character's defence
	 	then the damage taken is reduced to 1.
	*/
	if(damage<=(this->stats.Defence)) this->stats.HP = this->stats.HP - 1;
	else{
		damage = damage - this->stats.Defence;//damage taken from hp is the difference of damage taken and Defence stat
		this->stats.HP = this->stats.HP - damage;
		std::cout << "you took " << damage << " damage.\n";
	}
}
void character::equip(Item i){//function to equip item to character equipment 
	bool empty_spot = false;//key that checks if we found an open slot in the equipment list
	int x=0;
	while(!empty_spot){//while a slot hasn't been found
		if(x==5){//if you've gone beyond the list
			exchange(i);//exchange this item for another already equiped
			empty_spot = true;//exit loop key
		}
		else if(this->eq.has_item[x]==false){//if there is an empty slot
			dequip(x);//remove item from slot and delete object
			this->eq.equips[x] = &i;//add the new item to the list
			this->equip_stat = this->equip_stat + i.getStat();//change the equipment stats
			this->eq.has_item[x] = true;//change the slot unavailabity to true
			empty_spot = true;//exit loop key
		}
	}
}
void character::exchange(Item i){//function to exhange new item for item already equiped
	std::cout << "This is your list of equipment\n";
	//display list
	for(int j=0;j<5;j++){
		std::cout << j+1 << ". " << this->eq.equips[j]->getName() << "\n";
	}
	std::cout << "Which would you like to exchange?\n";
	std::cout << "Press 6 to exit";
	int input;
	std::cin >> input;
	if(input>0 && input<7){//if 1-5 continue
		if(input==6) ;//exit
		else{// exchange
			dequip(input);
			this->eq.equips[input] = &i;//set the pointer to the object
			this->equip_stat = this->equip_stat + i.getStat();
			this->eq.has_item[input] = true;
		}
	}
	else{//not 1-5
		while(input>6 || input<1){
			std::cout << "Please enter a correct number\n";
			std::cin >> input;
		}
		if(input==6) ;//exit
		else{// exchange
			dequip(input);
			this->eq.equips[input] = &i;
			this->equip_stat = this->equip_stat + i.getStat();
			this->eq.has_item[input] = true;
		}
	}
	
}
void character::dequip(int item_slot){//function that removes item from equipment list
	this->equip_stat = this->equip_stat - this->eq.equips[item_slot]->getStat();//update equipment stat
	delete this->eq.equips[item_slot];//delete the item object from the list
	this->eq.has_item[item_slot] = false;//set the slot to open
}
Hero::Hero(std::string n):character(n){//Hero Constructor
	this->expr = 0;
	this->expr_cap = 10;
}
Hero::~Hero() {}//Hero Destructor
void Hero::levelUp(){//function to level up Hero
	Stat lvl_incr(1,3,3,2,0);//base increment of stats, possible change to increase relative to level
	this->stats = this->stats + lvl_incr;
	std::cout << "You level up'd\n";
}
void Hero::exp_update(int gain){//function that calculates experience gained
	expr += gain;//adds experience to the Hero
	if(expr>expr_cap){//if it's more than the cap, you level up
		levelUp();
		this->expr -= this->expr_cap;
		this->expr_cap = this->expr_cap * 3;
	}
}
