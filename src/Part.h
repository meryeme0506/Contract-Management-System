#ifndef PART
#define PART

class Part {
 float amount;
 tm start;
 tm end;

public:
Part();
Part(float a, tm start, tm end);
float getAmount();
time_t getStart();
time_t getEnd();
float interest();
};

#endif
