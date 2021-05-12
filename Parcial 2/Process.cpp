#include "Process.h"

//Constructor
Process::Process(int _pid, int _priority, int _arrival, int _burst, int _response, int _completition){
  this->pid = _pid;
  this->priority = _priority;
  this->arrival = _arrival;
  this->burst = _burst;
  this->response = _response;
  this->completion = _completition;
}

Process::Process(int _pid, int _priority, int _burst){
  this->pid = _pid;
  this->priority = _priority;
  this->burst = _burst;
}


//Destructor
Process::~Process(){}

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

//Setters
void Process::setPID(int a){
  this->pid = a;
}

void Process::setPriority(int a){
  this->priority = a;
}

void Process::setArrival(int a){
  this->arrival = a;
}

void Process::setBurst(int a){
  this->burst = a;
}

void Process::setResponse(int a){
  this->response = a;
}

void Process::setCompletion(int a){
  this->completion = a;
}
