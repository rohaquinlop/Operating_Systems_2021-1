#include "Scheduler.h"

template <class T>
Scheduler<T>::Scheduler(){
  this->actTime = 0;
  this->jobQueue = queue<Process*>();
  this->processedQueue = queue<Process*>();
  this->readyQueue = priority_queue<Process*, vector<Process*>, T>();
}
