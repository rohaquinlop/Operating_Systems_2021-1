#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(){
  //HTML Basic Structure, created by Robin Quintero and Jhon Londoño

  cout << "content-type: text/html" << endl << endl;
  cout << "<html lang =\"en\">" << endl;

  cout << "<head>" << endl;
    cout << "<meta charset=\"UTF-8\">" << endl;
    cout << "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">" << endl;
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
    cout << "<title>" << endl;
      cout << "System Information" << endl; //Change Title
    cout << "</title>" << endl;
  cout << "</head>" << endl;

  cout << "<body>" << endl;
  //HTML Body
  
  //cout << "<>" << endl;
  /*
  - El numero de procesadores de una maquina
  - El numero de procesos corriendo
  - Cantidad de memoria de la maquina
  - Total de interrupciones ejecutadas
  */
  int cores = sysconf(_SC_NPROCESSORS_ONLN); //Command to check number of processors in Linux system.

  cout << "<h1>System Information</h1>" << endl;
  cout << "<tr><td>" << "La cantidad de procesadores del sistema es de " << cores << "." << "</td></tr>";  
  
  cout << "</body>" << endl;
  cout << "</html>" << endl;

  return 0;
}