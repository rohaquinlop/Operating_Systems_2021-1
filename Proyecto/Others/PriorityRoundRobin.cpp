#include "PriorityRoundRobin.h"

PriorityRoundRobin::PriorityRoundRobin(int _quantum, vector<Process*> processes) : Scheduler<PriorityRR>(processes) {
  this->quantum = _quantum;
}

void PriorityRoundRobin::startProcessing() {
  int i = 0;
  bool flag = 0;

  map<int, int> originalArrivalTime;
  map<int, int> originalBurstTime;
  queue<Process*>q = jobQueue;

  while (!q.empty()) {
    originalArrivalTime[q.front()->getPID()] = q.front()->getArrival();
    originalBurstTime[q.front()->getPID()] = q.front()->getBurst();

    q.pop();
  }


  while (!jobQueue.empty()) {
    if (jobQueue.front()->getArrival() <= actTime) {
      while (!jobQueue.empty() and jobQueue.front()->getArrival() <= actTime) {
        readyQueue.push(jobQueue.front());
        jobQueue.pop();
      }
      //Process the readyQueue

      while (!readyQueue.empty()) {
        Process* p = readyQueue.top();
        readyQueue.pop();

        if (p->getBurst() <= quantum) {
          p->setArrival(originalArrivalTime[p->getPID()]);
          p->setResponse(actTime - p->getArrival());

          actTime += p->getBurst();
          p->setBurst(originalBurstTime[p->getPID()]);
          p->setCompletion(actTime);
          p->setTurnAround(p->getCompletion() - p->getArrival());

          processedVector.push_back(p);
        }
        else {
          actTime += quantum;

          p->setBurst(p->getBurst() - quantum);
          p->setArrival(actTime);

          if (p->getArrival() > actTime) {
            jobQueue.push(p);
          }
          else readyQueue.push(p);
        }
      }
    }
    else actTime++;
  }
}