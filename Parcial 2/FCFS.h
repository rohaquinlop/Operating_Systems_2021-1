#ifndef FCFS_H
#define FCFS_H

#include "Process.h"

class FCFS{
public:
  bool operator()(Process* a, Process* b);
};

#endif