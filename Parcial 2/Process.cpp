#include "Process.h"

//Constructor
Process::Process(int _pid, int _priority, int _arrival, int _burst, int _response, int _completion){
  this->pid = _pid;
  this->priority = _priority;
  this->arrival = _arrival;
  this->burst = _burst;
  this->response = _response;
  this->completion = _completion;
}

Process::Process(int _pid, int _priority, int _arrival, int _burst){
  this->pid = _pid;
  this->priority = _priority;
  this->arrival = _arrival;
  this->burst = _burst;
}

Process::Process(Process& p){
  this->pid = p.pid;
  this->priority = p.priority;
  this->arrival = p.arrival;
  this->burst = p.burst;
  this->response = p.response;
  this->completion = p.completion;
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

void Process::setTurnAround(int a){
  this->turnAround = a;
}
