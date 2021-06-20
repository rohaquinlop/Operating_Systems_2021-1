#include "RoundRobin.h"

RoundRobin::RoundRobin(int _quantum, vector<Process*> processes) : Scheduler<FCFS>(processes) {
  this->quantum = _quantum;
}