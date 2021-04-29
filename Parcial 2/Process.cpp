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
