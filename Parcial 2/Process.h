#ifndef PROCESS_H
#define PROCESS_H

class Process{
private:
  int pid;        //process id
  int priority;   //priority-algorithm
  int arrival;    //arrival time
  int burst;      //time required to execute
  int response;   //time from arrival to the first time it started
  int completion; //final time

public:
  Process();
  Process(int a, int b, int c, int d, int e, int f);
  ~Process();

  int getPID();

};

#endif