#include <string>
#include <list>
#include <ctime>
#include <iostream>
#include "Facility.h"

Facility::Facility(){}

Facility::Facility(std::string name, tm s, tm f, float amount, float i, std::string curr, std::list<Institution> l){
  this->name = name;
  this->start = s;
  this->end = f;
  this->initAmount = amount;
  this->currAmount = amount;
  this->interestRate = i;
  this->currency = curr;
  this->lenders = l;
  this->portfolio = Portfolio();
}

void Facility::setAmount(float a){
  this->currAmount = a;
}

float Facility::getCurrAmount(){
  return this->currAmount;
}

float Facility::getInterestRate(){
  return this->interestRate;
}

void Facility::addPart(Part p){
  this->parts.emplace_back(p);
  // returns the difference in seconds
  double periode = difftime(p.getEnd(), p.getStart());
  // convert to days
  periode = periode/60/60/24;
  float interest = (periode/365)*this->interestRate*p.getAmount();
  this->portfolio.addInterest(interest);
  this->setAmount(this->currAmount-p.getAmount());
}

tm Facility::getStart(){
  return this->start;
}

tm Facility::getEnd(){
  return this->end;
}

float Facility::getInitAmount(){
  return this->initAmount;
}

float Facility::getRate(){
  return this->interestRate;
}

std::string Facility::getCurr(){
  return this->currency;
}

std::list<Institution> Facility::getLenders(){
  return this->lenders;
}

std::list<Part> Facility::getParts(){
  return this->parts;
}

Portfolio Facility::getPortfolio(){
  return this->portfolio;
}

std::string Facility::getName(){
  return this->name;
}

