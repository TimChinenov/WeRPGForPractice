// include libraries
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <fstream>
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
void loadT(string name);//loads text from file(parameter is filename)
void stage1(Hero &myHero);//demo
void inBattle(Hero &myHero,character &enemy);
void parseT(string text);//parses text with the dilimiter "..."

// ============================================================================
// ============================================================================

//Start main here
int main (int argc, char* argv[]) {
  string choice; //This variable holds results of decisions made
  choice = start_or_load();//get user choice
  starting_game(choice);
  /*
  while (true){
    string response;
    std::cout << "What would you like to do?" << endl;

    cout << "For possible commands, enter \"Help\"" << endl;

    //Ensures the entered command is a valid entry. Helps prevent machine crashing behaviors
    do{
      getline(cin, response);
    }while(!is_valid(response));
    
    process_command(response);
  }*/
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
    string n = "";
    cout << "Please enter the name you want for your character\n";
    do{
      getline(cin,n);
    }while(!is_valid(n));
    static Hero newGuy(n);
    cout << newGuy.character::getName() << " has been born. Congrats, you're temporarily responsible for someone\n";
    stage1(newGuy);
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
    std::cout << "begining saving process";
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
  else if(com == "fight"){
    //inBattle();
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
void loadT(string name){
  ifstream i(name);
  if(i.is_open()){
    cout << i.rdbuf() << "\n";
  }
  else{
   cout << "I believe that was an invalid filename.\n";
   cout << "Please contact the staff in order to fix this problem.\n";
   exit(0);
  }
}
void loadS(string name){
  ifstream i(name);
  string par;//paragraph
  if(i.is_open()){
    while(!i.eof()){
      getline(i,par);
      parseT(par);
    }
  }
  else{
   cout << "I believe that was an invalid filename.\n";
   cout << "Please contact the staff in order to fix this problem.\n";
   exit(0);
  }
}
void parseT(string text){
  string temp;
  size_t pos = text.find("...");
  if(pos == std::string::npos) cout << text << '\n';
  while(pos != std::string::npos){
    if(text=="");
    else{
      cout << text.substr(0,pos) << '\n';
      temp = text.substr(pos+3);
      text = temp; 
      pos = text.find("...");
      getchar();
    }
  }
  if(temp != "") cout << temp << '\n';
}
void stage1(Hero &myHero){
  cout << "\033[2J\033[1;1H"<< "press Enter ";//keyword that clears screen for linux and certain windows cmpilers
  getchar();
  loadS("../lib/stage1.txt");
  getchar();
  cout << "\033[2J\033[1;1H";
  loadS("../lib/awoke.txt");
}
void inBattle(Hero &myHero,character &enemy){
  ;
}