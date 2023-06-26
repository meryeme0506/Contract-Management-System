#include <string>
#include <list>
#include <ctime>
#include <iostream>
#include "Portfolio.h"


Portfolio::Portfolio(){
  this->interest = 0;
};

void Portfolio::addInterest(float i){
  this->interest += i;
};

float Portfolio::getInterest(){
  return this->interest;
};
