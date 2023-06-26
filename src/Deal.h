#ifndef DEAL
#define DEAL

#include "Institution.h"
#include "Facility.h"

class Deal {
 std::string contract;
 Institution agent;
 std::list<Institution> pool;
 Institution borrower;
 float amount;
 std::string currency;
 tm signature;
 tm maturity;
 std::string status;
 std::list<Facility> facilities;

public:
  Deal();
  Deal(std::string cont, Institution a, std::list<Institution> pool, Institution b, float amount, std::string curr, tm debut, tm fin);
  std::string getContract();
  Institution getAgent();
  std::list<Institution> getPool();
  Institution getBorrower();
  float getAmount();
  std::string getCurrency();
  tm getSignature();
  tm getMaturity();
  std::string getStatus();
  void changeStatus();
  std::list<Facility> getFacilities();
  void addFacility(Facility f);
};

#endif
