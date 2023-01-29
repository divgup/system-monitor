#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <unistd.h>
#include <fstream>
#include <sstream>
#include <vector>
class Processor {
 public:
  Processor(){ 
    prev1 = 0;
    prev2 = 0;
    prev3 = 0;
    prev4 = 0;
}; 
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    float cpuUsage=0.0;
    float prev1;
    float prev2;
    float prev3;
    float prev4;
};

#endif