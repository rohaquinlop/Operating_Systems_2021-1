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
  Scheduler(vector<Process*> processes){
    this->actTime = 0;
    this->jobQueue = queue<Process*>();

    for(Process* p: processes) this->jobQueue.push(p);

    this->processedQueue = queue<Process*>();
    this->readyQueue = priority_queue<Process*, vector<Process*>, T>();
  }

  //Functions

  void startProcessing(){
    while(!jobQueue.empty()){
      if(jobQueue.front()->getArrival() <= actTime){
        while(!jobQueue.empty() and jobQueue.front()->getArrival() <= actTime){
          readyQueue.push(jobQueue.front());
          jobQueue.pop();
        }
        //Process the readyQueue
        
        while(!readyQueue.empty()){
          readyQueue.top()->setResponse(actTime-readyQueue.top()->getArrival());
          
          actTime += readyQueue.top()->getBurst();
          
          readyQueue.top()->setCompletion(actTime);
          readyQueue.top()->setTurnAround(readyQueue.top()->getCompletion()-readyQueue.top()->getArrival());

          processedQueue.push(readyQueue.top());
          readyQueue.pop();
        }
      }
      else actTime++;
    }
  }

  void drawGanttChart(){
    cout << left << setw(10) << "Process ID " << left << setw(10) << "| Time" << endl;

    while(!processedQueue.empty()){
      auto p = processedQueue.front();
      string s = "";

      for(int i = 0; i < p->getArrival() + p->getResponse(); i++) s += " ";

      s += to_string(p->getArrival() + p->getResponse()) + "->|";

      for(int i = 0; i < p->getBurst(); i++) s+= "-";

      s += "|<-" + to_string(p->getCompletion());

      cout << left << setw(10) << p->getPID() << left << s << endl;
      processedQueue.pop();
    }
  }

};


#endif