#ifndef FACILITY
#define FACILITY

#include "Institution.h"
#include "Portfolio.h"
#include "Part.h"

class Facility {
 std::string name;
 tm start;
 tm end;
 float initAmount;
 float currAmount;
 float interestRate;
 std::string currency;
 std::list<Institution> lenders;
 std::list<Part> parts;
 Portfolio portfolio;

public:
  Facility();
  Facility(std::string name, tm s, tm f, float amount, float i, std::string curr, std::list<Institution> l);
  void setAmount(float a);
  float getCurrAmount();
  float getInterestRate();
  void addPart(Part p);
  tm getStart();
  tm getEnd();
  float getInitAmount();
  float getRate();
  std::string getCurr();
  std::list<Institution> getLenders();
  std::list<Part> getParts();
  Portfolio getPortfolio();
  std::string getName();
};

#endif
