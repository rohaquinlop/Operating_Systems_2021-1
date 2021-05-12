#ifndef PRIORITY_H
#define PRIORITY_H

#include "Process.h"

class Priority{
public:
  bool operator()(Process* a, Process* b);
};

#endif