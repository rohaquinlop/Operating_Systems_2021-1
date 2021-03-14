#include <unistd.h>
#include <iostream>

using namespace std;

int main(){
  pid_t nuevo;

  for(int num = 0; num < 2; num++){
    nuevo = fork();
    if(nuevo == 0) break;
  }
  nuevo = fork();
  nuevo = fork();

  cout << "soy el proceso " << getpid() << " y mi padre es " << getppid() << endl;

  return 0;
}

