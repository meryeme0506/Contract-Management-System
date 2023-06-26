#include <string>
#include <list>
#include <ctime>
#include "Deal.h"

Deal::Deal(std::string cont, Institution a, std::list<Institution> pool, Institution b, float amount, std::string curr, tm debut, tm fin){
  this->contract = cont;
  this->agent = a;
  this->pool = pool;
  this->borrower = b;
  this->amount = amount;
  this->currency = curr;
  this->signature = debut;
  this->maturity = fin;
  this->status = "closed";
}

Deal::Deal(){
}

std::string Deal::getContract(){
  return this->contract;
}

Institution Deal::getAgent(){
  return this->agent;
}

std::list<Institution> Deal::getPool(){
  return this->pool;
}

Institution Deal::getBorrower(){
  return this->borrower;
}

float Deal::getAmount(){
  return this->amount;
}

std::string Deal::getCurrency(){
  return this->currency;
}

tm Deal::getSignature(){
  return this->signature;
}

tm Deal::getMaturity(){
  return this->maturity;
}

std::string Deal::getStatus(){
  return this->status;
}

void Deal::changeStatus(){
  if (this->status == "closed") {
    this->status = "terminated";
  } else {
    this->status = "closed";
  }
}

std::list<Facility> Deal::getFacilities(){
  return this->facilities;
}

void Deal::addFacility(Facility f){
  this->facilities.emplace_back(f);
}
