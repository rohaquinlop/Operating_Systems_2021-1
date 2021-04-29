#include "Process.h"

Process::Process(int a, int b, int c, int d, int e, int f){
  this->pid = a;
  this->priority = b;
  this->arrival = c;
  this->burst = d;
  this->response = e;
  this->completion = f;
}

int Process::getPID(){
  return this->pid;
}
