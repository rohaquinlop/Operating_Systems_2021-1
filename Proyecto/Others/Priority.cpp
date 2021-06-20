#include "Priority.h"

bool Priority::operator()(Process* a, Process* b){
  return a->getPriority() > b->getPriority();
}
