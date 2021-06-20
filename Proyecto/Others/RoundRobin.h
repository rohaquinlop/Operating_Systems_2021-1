#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

#include<bits/stdc++.h>
#include "Scheduler.h"
#include "FCFS.h"

class RoundRobin : public Scheduler<FCFS> {
public:
  int quantum;

  //Constructor
  RoundRobin(int _quantum, vector<Process*> processes);
};

#endif