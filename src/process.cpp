#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;


Process::Process(int pid){
    pid_ = pid;
}

// TODO: Return this process's ID
int Process ::Pid() const { 

    return pid_; 
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const{ 
    
    float utilization;

    try{
        utilization = float(LinuxParser::ActiveJiffies(Pid())) / ( float(LinuxParser::UpTime()) - float(LinuxParser::UpTime(Pid())) );
        //For debugging
       // std::cout << "ActiveJiffies = " << LinuxParser::ActiveJiffies(Pid()) << std::endl << "Uptime() = " << LinuxParser::UpTime() << std::endl << "UpTime(Pid()) = " << LinuxParser::UpTime(Pid()) << std::endl;
       // std::cout << "utilization = " << utilization << std::endl;
       // std::cin.get();
    } catch(...) {
        utilization = 0;
    } 
    return utilization;
}

// TODO: Return the command that generated this process
string Process::Command() const{ 

    return LinuxParser::Command(Pid()); 
}

// TODO: Return this process's memory utilization
string Process::Ram() const{ 

    return LinuxParser::Ram(Pid()); 
}

// TODO: Return the user (name) that generated this process
string Process::User() const{

    return LinuxParser::User(Pid()); 
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const{ 

    return LinuxParser::UpTime(Pid()); 
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const a) const{ 

    return ( a.CpuUtilization() < CpuUtilization() );

}