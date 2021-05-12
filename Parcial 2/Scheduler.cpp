#include "Scheduler.h"

template <class T>
Scheduler<T>::Scheduler(vector<Process*> processes){
  this->actTime = 0;
  this->jobQueue = queue<Process*>();

  for(Process* p: processes) this->jobQueue.push(p);

  this->processedQueue = queue<Process*>();
  this->readyQueue = priority_queue<Process*, vector<Process*>, T>();
}

template <class T>
void Scheduler<T>::startProcessing(){
  while(!jobQueue.empty()){
    if(jobQueue.front() <= actTime){
      while( jobQueue.front() <= actTime){
        readyQueue.push(jobQueue.front());
        jobQueue.pop();
      }
      //Process the readyQueue
      
      while(!readyQueue.empty()){
        //
      }
    }
    else actTime++;
  }
}
