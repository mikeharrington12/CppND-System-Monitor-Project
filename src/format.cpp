#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    
  long hours, minutes;
  hours = seconds / 3600;
  seconds = seconds % 3600;
  minutes = seconds / 60;
  seconds = seconds % 60;
  
  string hrs = std::to_string(hours);
  hrs.insert(0, 2 - hrs.length(), '0');

  string mins = std::to_string(minutes);
  mins.insert(0, 2 - mins.length(), '0');
  
  string secs =std::to_string(seconds);
  secs.insert(0, 2 - secs.length(), '0');
  
  return hrs + ":" + mins + ":" + secs;
    
}