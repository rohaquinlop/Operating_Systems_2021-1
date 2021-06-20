#ifndef SJF_H
#define SJF_H

#include "Process.h"

class SJF{
public:
  bool operator()(Process* a, Process* b);
};

#endif