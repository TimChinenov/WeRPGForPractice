// include libraries
#include <iostream>
#include <string>
//include headers below here
#include "stat.h"
#include "item.h"
#include "character.h"

//prototyp functions below
char save_or_load();
void starting_game(char choice);
// ============================================================================
// ============================================================================

//Start main here
int main (int argc, char* argv[]) {
  char choice; //This variable holds results of decisions made
  choice = save_or_load();//get user choice
  starting_game(choice);
}


//the following function will initiate the basic introduction to the game
char save_or_load(){
  char action;
  std::cout << "Welcome to WeRPGForPractice\n";
  std::cout << "Would you likst to start a new game or load a game [N/L]\n";
  std::cin >> action;
  return action;

}

void starting_game(char choice)
{
  if (choice == 'n' || choice == 'N' || choice == 'new' || choice == 'New')
  {
      //start new game here if the choice was new
    std::cout << "Starting new game...";
  }
  else if (choice == 'l' || choice || 'L' || choice == 'load' ||\
   choice == 'load')
  {
    //load list of all games
    std::cout << "Load games...";
  }
  else //if statement is not interpreted
  {
    std::cout << "LOL can you not follow basic instructions?";
  }
}
