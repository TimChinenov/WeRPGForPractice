// include libraries
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
//include headers below here
#include "stat.h"
#include "item.h"
#include "character.h"


using namespace std;
//prototyp functions below

string Help();
bool is_valid(string input);
void process_command(string choice);
string start_or_load();
void starting_game(string choice);

// ============================================================================
// ============================================================================

//Start main here
int main (int argc, char* argv[]) {
  string choice; //This variable holds results of decisions made
  choice = start_or_load();//get user choice
  starting_game(choice);

  while (true){
    string response;
    std::cout << "What would you like to do?" << endl;

    cout << "For possible commands, enter \"Help\"" << endl;

    //Ensures the entered command is a valid entry. Helps prevent machine crashing behaviors
    do{
      getline(cin, response);
    }while(!is_valid(response));
    
    process_command(response);
  }
  return 0;
}


//the following function will initiate the basic introduction to the game
string start_or_load(){
  string action;
  std::cout << "Welcome to WeRPGForPractice\n";
  do{
    std::cout << "Would you like to start a new game or load a game [N/L]\n";
    getline(cin, action);
  }
  while(!is_valid(action));


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
  //Input too long
  if(input.length() > 255){
    return false;
  }
  //Checks all characters are alphanumeric or the underscore character
  //TODO: See if this check does not allow empty string ("")
  regex check("^\\w+");
  if(!regex_match(input.begin(), input.end(), check)){
    return false;
  }
  return true;
}

void process_command(string com)
{
  if (com == "save" || com == "S" || com == "s" || com == "Save")
  {
    std::cout << "beging saving process";
  }
  else if (com == "exit" || com == "Exit")
  {
    std::cout << "exit game";
    //I imagine that the command below is what we ultimately will want to use
    //to kill the process. However, we will have to call appropriate destructors
    //before doing so.
    //std::exit;
  }
  else if (com == "help")
  {
    Help();
  }
}

std::string Help()
{
  stringstream out;
  out << "The following is help text.\n";
  out << "The following commands are available to you.\n";
  out << "Save\n";
  out << "Alternatives: 'save', 's', 'S'\n";
  out << "Saves all current information into a file that you can load"
               "later on in the game. This command can be run at any point"
               "When the option to input information is present.\n\n";
  out << "Exit\n";
  out << "Alternatives: 'exit'\n";
  out << "Exits the game without saving data.\n";
  return out.str();
}