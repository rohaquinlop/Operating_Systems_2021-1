#include "SJF.h"

bool SJF::operator()(Process* a, Process* b){
  if( a->getBurst() == b->getBurst() ){
    return a->getArrival() < b->getArrival();
  }
  return a->getBurst() < b->getBurst();
}
