#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 

  long totalOld, totalNew, activeNew, idleOld, idleNew;
  activeNew = JActive();
  idleNew = JIdle();
  totalNew = JTotal();

  totalOld = Total();
  idleOld = Idle();

  Update(idleNew, activeNew, totalNew);

  float totalDelta = float(totalNew) - float(totalOld);
  float idleDetla = float(idleNew) - float(idleOld);

  float utilization = (totalDelta - idleDetla) / totalDelta;
  return utilization;

}

void Processor::Update(long idle, long active, long total) {
  active_ = active;
  idle_ = idle;
  total_ = total;
}

long Processor::Active() { 
    return active_; 
}

long Processor::Idle() { 
    return idle_; 
}

long Processor::Total() { 
    return total_; 
}

long Processor::JActive() { 
    return LinuxParser::ActiveJiffies(); 
}

long Processor::JIdle() { 
    return LinuxParser::IdleJiffies(); 
}

long Processor::JTotal() { 
    return LinuxParser::Jiffies(); 
}