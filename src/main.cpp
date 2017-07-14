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

  while (true){
    char response;
    std::cout << "What would you like to do?";
    std::cin << response;
    process_command(response);
  }
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

void process_command(char com)
{
  if (com == 'save' || com == 'S' || com == 's' || com == 'Save')
  {
    std::cout << "beging saving process";
  }
  else if (com == 'exit' || com == 'Exit')
  {
    std::cout << "exit game";
    //I imagine that the command below is what we ultimately will want to use
    //to kill the process. However, we will have to call appropriate destructors
    //before doing so.
    //std::exit;
  }
  else if (com == 'help')
  {
    Help();
  }
}

std::String Help()
{
  std::cout << "The following is help text.\n";
  std::cout << "The following commands are available to you.\n";
  std::cout << "Save\n";
  std::cout << "Alternatives: 'save', 's', 'S'\n";
  std::cout << "Saves all current information into a file that you can load"
               "later on in the game. This command can be run at any point"
               "When the option to input information is present.\n\n";
  std::cout << "Exit\n";
  std::cout << "Alternatives: 'exit'\n";
  std::cout << "Exits the game without saving data."
  return;
}
