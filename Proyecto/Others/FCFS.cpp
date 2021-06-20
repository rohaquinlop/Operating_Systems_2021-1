#include "FCFS.h"

bool FCFS::operator()(Process* a, Process* b){
  return a->getArrival() < b->getArrival();
}
