#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  void Update(long active, long idle, long total); 
  long Idle();
  long Active();  
  long Total();
  long JActive();
  long JIdle();
  long JTotal();

  // TODO: Declare any necessary private members
 private:
    long active_, idle_, total_;
};

#endif