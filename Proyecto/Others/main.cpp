#include <bits/stdc++.h>
#include "Process.h"
#include "Scheduler.h"
#include "FCFS.h"
#include "Priority.h"
#include "SJF.h"
#include "RoundRobin.h"
#include "PriorityRoundRobin.h"

#include <stdlib.h>
#include <time.h>
#include <thread>

using namespace std;

bool cmp(Process* a, Process* b) {
  return a->getArrival() < b->getArrival();
}

int main() {
  int cntProcess, prio, burst, burstRange, arrival, quantum;
  vector<Process*> processes;
  srand(time(NULL)); // random seed

  cout << "Number of processes: ";
  cin >> cntProcess;

  cout << "Burst range: ";
  cin >> burstRange;

  cout << "Quantum value: ";
  cin >> quantum;

  for (int i = 0; i < cntProcess; i++) {
    prio = rand() % 10 + 1; // random (1..10)
    arrival = rand() % (cntProcess + 1); // random (0..cntProcess)
    burst = rand() % burstRange + 1; // random (1.. burstRange)
    processes.push_back(new Process(i, prio, arrival, burst));
  }

  sort(processes.begin(), processes.end(), cmp);

  cout << left << setw(10) << "PID" << setw(13) << "Arrival time" << setw(10) << "Priority" << setw(10) << "Burst" << endl;

  for (Process* p : processes) {
    cout << left << setw(10) << p->getPID() << setw(13) << p->getArrival() << setw(10) << p->getPriority() << setw(10) << p->getBurst() << endl;
  }

  cout << endl;

  Scheduler<FCFS>* fcfs = new Scheduler<FCFS>(processes);
  Scheduler<SJF>* sjf = new Scheduler<SJF>(processes);
  Scheduler<Priority>* priority = new Scheduler<Priority>(processes);
  RoundRobin* rr = new RoundRobin(quantum, processes);
  PriorityRoundRobin* prr = new PriorityRoundRobin(quantum, processes);

  auto f1 = [](Scheduler<FCFS>* x) {
    x->startProcessing();
  };

  auto f2 = [](Scheduler<SJF>* x) {
    x->startProcessing();
  };

  auto f3 = [](Scheduler<Priority>* x) {
    x->startProcessing();
  };

  auto f4 = [](RoundRobin* x) {
    x->startProcessing();
  };

  auto f5 = [](PriorityRoundRobin* x) {
    x->startProcessing();
  };

  thread th1(f1, fcfs);
  thread th2(f2, sjf);
  thread th3(f3, priority);
  thread th4(f4, rr);
  thread th5(f5, prr);

  th1.join();
  th2.join();
  th3.join();
  th4.join();
  th5.join();

  cout << "FCFS" << endl;
  fcfs->drawGanttChart();
  cout << endl;

  cout << "SJF" << endl;
  sjf->drawGanttChart();
  cout << endl;

  cout << "Priority" << endl;
  priority->drawGanttChart();
  cout << endl;

  cout << "Round Robin" << endl;
  rr->drawGanttChart();
  cout << endl;

  cout << "Priority Round Robin" << endl;
  prr->drawGanttChart();
  cout << endl;

  return 0;
}