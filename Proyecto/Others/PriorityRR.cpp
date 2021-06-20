#include "PriorityRR.h"

bool PriorityRR::operator()(Process* a, Process* b) {
  if (a->getArrival() == b->getArrival())
    return a->getPriority() > b->getPriority();
  return a->getArrival() > b->getArrival();
}
