#include "Process.h"

Process::Process(int a, int b, int c, int d, int e, int f){
  this->pid = a;
  this->priority = b;
  this->arrival = c;
  this->burst = d;
  this->response = e;
  this->completion = f;
}

//Getters

int Process::getPID(){
  return this->pid;
}

int Process::getPriority(){
  return this->priority;
}

int Process::getArrival(){
  return this->arrival;
}

int Process::getBurst(){
  return this->burst;
}

int Process::getResponse(){
  return this->response;
}

int Process::getCompletion(){
  return this->completion;
}
