#ifndef GANTTCHART_H
#define GANTTCHART_H

#include "bits/stdc++.h"
#include "Process.h"

using namespace std;

class GanttChart{
public:
  //Attributes
  vector<Process*> processes;


  //Methods
  GanttChart();
  void addProcess(Process* p);
  void draw();
  int getMaxValue();
};


#endif