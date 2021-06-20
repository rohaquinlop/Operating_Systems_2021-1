#ifndef PRIORITYROUNDROBIN_H
#define PRIORITYROUNDROBIN_H

#include<bits/stdc++.h>
#include "Scheduler.h"
#include "PriorityRR.h"

class PriorityRoundRobin : public Scheduler<PriorityRR> {
public:
  int quantum;

  //Constructor
  PriorityRoundRobin(int _quantum, vector<Process*> processes);

  //Functions
  using Scheduler<PriorityRR>::drawGanttChart;
  void startProcessing();
};

#endif