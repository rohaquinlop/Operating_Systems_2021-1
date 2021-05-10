#include "GanttChart.h"

GanttChart::GanttChart(){
  this->processes = vector<Process*>();
}

void GanttChart::addProcess(Process* p){
  this->processes.push_back(p);
}

int GanttChart::getMaxValue(){
  int ans = 0;
  for(Process* p : this->processes){
    ans = max(ans, p->getCompletion());
  }

  return ans;
}

void GanttChart::draw(){

  cout << left << setw(10) << "Process ID " << left << setw(10) << "| Time"

  for(Process* p : this->processes){
    //
  }
}
