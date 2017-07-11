// include libraries
#include <iostream>
#include <regex>
#include <string>
//include headers below here
#include "stat.h"
#include "item.h"
#include "character.h"


using namespace std;
//prototyp functions below
string save_or_load();
void starting_game(string choice);
bool is_valid(string input);
// ============================================================================
// ============================================================================

//Start main here
int main (int argc, char* argv[]) {
  string choice; //This variable holds results of decisions made
  choice = save_or_load();//get user choice
  starting_game(choice);
}


//the following function will initiate the basic introduction to the game
string save_or_load(){
  string action;
  std::cout << "Welcome to WeRPGForPractice\n";
  std::cout << "Would you likst to start a new game or load a game [N/L]\n";
  do{
    getline(cin, action);
  }while(!is_valid(action));
  
  
  return action;

}

void starting_game(string choice)
{
  if (choice == "n" || choice == "N" || choice == "new" || choice == "New")
  {
      //start new game here if the choice was new
    std::cout << "Starting new game..." << endl;
  }
  else if (choice == "l" || choice == "L" || choice == "load" || choice == "load")
  {
    //load list of all games
    std::cout << "Load games..." << endl;
  }
  else //if statement is not interpreted
  {
    std::cout << "LOL can you not follow basic instructions?" << endl;
  }
}

bool is_valid(string input){
  //Inpu too long
  if(input.length() > 255){
    return false;
  }
  //Checks all characters are alphanumeric or the underscore character
  regex check("^\\w+");
  if(!regex_match(input.begin(), input.end(), check)){
    return false;
  }
  return true;
}
