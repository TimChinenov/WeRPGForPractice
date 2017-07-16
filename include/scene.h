#ifndef SCENE_H   // if x.h hasn't been included yet...
#define SCENE_H   //   #define this so the compiler knows it has been included
#include "stat.h"
#include "item.h"
#include "action.h"
#include "character.h"
#include <string>
#include <iostream>
/*
The following is the header for the scene class. This class will keep track
of all monsters, characters, items, etc  that are in play. In addition,
it wall contain terrain information and enviornment conditions. 
*/
class scene{
  std::string adventure_name; //Name of this story/scene
  Character hero; //a pointer to the player
  Character monsters; //a set of pointers for all monsters
  Character npcs; //a set of pointers for all non-enemies

};

#endif
