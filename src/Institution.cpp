#include <string>
#include <list>
#include <ctime>
#include "Institution.h"

Institution::Institution(std::string name, float a, std::string r){
  this->name = name;
  this->amount = a;
  this->role = r;
}

Institution::Institution(){
}

std::string Institution::getName(){
  return this->name;
}

float Institution::getAmount(){
  return this->amount;
}

std::string Institution::getRole(){
  return this->role;
}
