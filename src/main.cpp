// include libraries
#include <iostream>
#include <string>
//include headers below here
#include "stat.h"
#include "item.h"
#include "character.h"

//prototyp functions below
std::string save_or_load();
void starting_game(std::string choice);
void new_game();
void stage1(Hero aHero);
// ============================================================================
// ============================================================================

//Start main here
int main (int argc, char* argv[]) {
  std::string choice; //This variable holds results of decisions made
  choice = save_or_load();//get user choice
  starting_game(choice);
}


//the following function will initiate the basic introduction to the game
std::string save_or_load(){
  std::string action;
  std::cout << "Welcome to WeRPGForPractice\n";
  std::cout << "Would you likst to start a new game or load a game [N/L]\n";
  std::cin >> action;
  return action;
}

void starting_game(std::string choice)
{
  if (choice == "n" || choice == "N" || choice == "new" || choice == "New")
  {
      //start new game here if the choice was new
    std::cout << "Starting new game...";
  }
  else if (choice == "l" || choice == "L" || choice == "load" ||\
   choice == "load")
  {
    //load list of all games
    std::cout << "Load games...";
  }
  else //if statement is not interpreted
  {
    std::cout << "LOL can you not follow basic instructions?";
  }
}
void new_game(){
  std::string name;
  std::cout << "What do you want your character's name to be?\n";
  std::cin >> name;
  Hero Person(name);

}
void stage1(Hero aHero){
  
}