#ifndef PRIORITYRR_H
#define PRIORITYRR_H

#include "Process.h"

class PriorityRR {
public:
  bool operator()(Process* a, Process* b);
};

#endif