#include "magic.h"

using namespace std;


string Magic::cast(unsigned int level){
  string out = "You cast " + this->spell_name + ". ";
  if(level >= this->level_req){
    out += this->effect_desc;
  }else{
    out += this->failure_desc;
  }
  return out;
}

