#include <unistd.h>
#include <cstddef>
#include <set>
#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "process.h"
#include <regex>
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

/*You need to complete the mentioned TODOs in order to satisfy the rubric criteria "The student will be able to extract and display basic data about the system."

You need to properly format the uptime. Refer to the comments mentioned in format. cpp for formatting the uptime.*/

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    

 }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { 
    string line;
    size_t pos;
    string temp1,temp2,ans;
    std::ifstream filestream("/proc/version");
    if (filestream.is_open()) {
        std::getline(filestream, line);
        {
            pos = line.find("(");
        }
        string substrin = line.substr(0,pos-1);
        std::istringstream s(substrin);
        s >> temp1 >> temp2 >> ans;
        
    }
    return ans;
 }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { 
  string line;
  vector<string> membuffer;
  std::ifstream filestream("/proc/meminfo");
  while(getline(filestream,line)){
    size_t found = line.find(":");
    string substrin = line.substr(found+1);
    remove(substrin.begin(),substrin.end(),' ');
    membuffer.push_back(substrin);
    
  }
  float totalMemory = stof(membuffer[0]);
  float freeMem = stof(membuffer[1]);
  float memUsed = (totalMemory-freeMem)/totalMemory;
  return memUsed;
}


// TODO: Return the operating system name
std::string System::OperatingSystem() { 
  string value;
  string key;
  string line;
  std::ifstream filestream("/etc/os-release");
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;

}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { 
  std::string line;
  int num;
  std::ifstream filestream("/proc/stat");
  if(filestream.is_open()){
    while(getline(filestream,line)){
      size_t found = line.find("procs_running");
      if(found!=string::npos){
        found = line.find(" ");
        num = stoi(line.substr(found+1));
      }
    }
    return num;
  }

}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { 
  string line;
  int num;
  std::ifstream filestream("/proc/stat");
  if(filestream.is_open()){
    while(getline(filestream,line)){
      size_t found= line.find("processes");
      if(found!=string::npos){
        found = line.find(" ");
        num = stoi(line.substr(found+1));
      }
    }
    return num;
  }
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {   
  std::ifstream filestream("/proc/uptime");
  std::string line;
  std::string uptime;
  if (filestream.is_open()){
    std::getline(filestream,line);
    std::istringstream linestream(line);
    linestream >> uptime;
  }
  // std::cout << uptime << std::endl;
  return stol(uptime);
}
