#include <bits/stdc++.h>
#include "Process.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "Priority.h"
#include "SJF.h"

#include <stdlib.h>
#include <time.h>

using namespace std;

bool cmp(Process* a, Process* b){
  return a->getArrival() < b->getArrival();
}

int main(){
  int cntProcess, priority, burst, burstRange, arrival;
  vector<Process*> processes;
  srand(time(NULL)); // random seed

  cout << "Number of processes: ";
  cin >> cntProcess;

  cout << "Burst range: ";
  cin >> burstRange;

  for(int i = 0; i < cntProcess; i++){
    priority = rand() % 10 + 1; // random (1..10)
    arrival = rand()%(cntProcess+1); // random (0..cntProcess)
    burst = rand() % burstRange + 1; // random (1.. burstRange)
    processes.push_back(new Process(i, priority, arrival, burst));
  }

  sort(processes.begin(), processes.end(), cmp);

  for(Process* p : processes){
    cout << p->getPID() << " " << p->getArrival() << " " << p->getPriority() << " " << p->getBurst() << endl;
  }

  Scheduler<FCFS> *scheduler = new Scheduler<FCFS>(processes);
  scheduler->startProcessing();
  scheduler->drawGanttChart();

  return 0;
}