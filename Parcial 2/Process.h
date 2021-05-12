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
  //constructor
  Process();
  Process(int _pid, int _priority, int _arrival, int _burst, int _response, int _completition);
  Process(int _pid, int _priority, int _burst);

  //destructor
  ~Process();

  //utility-functions
  //getters
  int getPID();
  int getPriority();
  int getArrival();
  int getBurst();
  int getResponse();
  int getCompletion();

  //setters
  void setPID(int a);
  void setPriority(int a);
  void setArrival(int a);
  void setBurst(int a);
  void setResponse(int a);
  void setCompletion(int a);

};
#endif