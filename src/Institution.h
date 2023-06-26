#ifndef INSTITUTION
#define INSTITUTION

class Institution {
 std::string name;
 float amount;
 std::string role;

public:
Institution();
Institution(std::string name, float a, std::string r);
std::string getName();
float getAmount();
std::string getRole();
};

#endif
