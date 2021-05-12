#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <bits/stdc++.h>
#include "Process.h"

using namespace std;

template <class T>
class Scheduler{
public:
  //As processes enter the system, they are put into the job queue, which consists of all process in the system
  int actTime;
  queue<Process*> jobQueue;
  queue<Process*> processedQueue;
  priority_queue<Process*, vector<Process*>, T> readyQueue;

  //Constructor
  Scheduler();

};


#endif