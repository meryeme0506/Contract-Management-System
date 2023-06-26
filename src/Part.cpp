#include <string>
#include <list>
#include <ctime>
#include "Part.h"

Part::Part(){

}

Part::Part(float a, tm start, tm end){
  this->amount = a;
  this->start = start;
  this->end = end;
}

float Part::getAmount(){
  return this->amount;
}

time_t Part::getStart(){
  return mktime(&(this->start));
}

time_t Part::getEnd(){
  return mktime(&(this->end));
}
