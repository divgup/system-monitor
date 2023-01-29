#include "processor.h"


// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    
    std::string line;
    std::string l;
    std::vector<long double> a;
    std::ifstream filestream("/proc/stat");
    std::getline(filestream,line);
    std::istringstream ss(line);
    int i = 0;
    while(ss >> l){  
        if(i > 0){
            a.push_back(std::stold(l));
        }
        i++;
    }
    
    float loadavg = ((a[0]+a[1]+a[2]) - (prev1 + prev2 + prev3)) / ((a[0]+a[1]+a[2]+a[3]) - (prev1 + prev2 + prev3 + prev4));
    prev1 = a[0];
    prev2 = a[1];
    prev3 = a[2];
    prev4 = a[3]; 
    this->cpuUsage = loadavg;
    return this->cpuUsage;
}