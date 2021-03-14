#include<unistd.h>
#include<iostream>

using namespace std;

int main(){
  pid_t n;

  for(int i = 0; i < 2; i++){
    n = fork();
    if(n == 0) break;
    cout << getpid() << " is still running" << endl;
  }

  cout << getpid() << " <- " << getppid() << endl;


  return 0;
}

