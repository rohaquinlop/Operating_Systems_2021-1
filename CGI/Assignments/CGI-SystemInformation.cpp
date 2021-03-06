#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

//This function allows to capture the output of a linux command in the terminal and use it.
string getCommandAns(string cmd){
  string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if(stream){
    while(!feof(stream)){
      if(fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    }
    pclose(stream);
  }
  return data;
}

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
                                                                              /*C++ instructions*/

  int cores = sysconf(_SC_NPROCESSORS_ONLN); //Command to check number of processors in Linux system.
  string processes = getCommandAns("ps -e | wc -l"); //Command to call the function and get the output of linux command "ps -e | wc -l". (Number of processes running)
  string totalRAM = getCommandAns("grep MemTotal /proc/meminfo"); //Command to call the function and get the output of linux command "grep MemTotal /proc/meminfo".(Total RAM memory)
  string availableRAM = getCommandAns("grep MemAvailable /proc/meminfo");//Command to call the function and get the output of linux command "grep MemAvailable /proc/meminfo".(Available RAM memory)
  totalRAM.erase(0,9); // Erase part of the output that is not important.
  availableRAM.erase(0,13); // Erase part of the output that is not important.
  string interruptsChain = getCommandAns("cat /proc/stat"); //Command to call the function and get the output of linux command "cat /proc/stat".(Information about interruptions)
  size_t found = interruptsChain.find("intr");//Position where the total interruptions identifier is (identifier = intr).

  //String processing for interruptions number.
  int spaces = 0; 
  string ans = ""; //Empty string to save the total specific interruptions number.

  //Loop used to extract the total specific interruptions number.
  for(found; found < interruptsChain.size(); found++){
    if(interruptsChain[found] == ' '){
      spaces += 1;
      if(spaces == 2){
        break;
      }
    }
    else{
      if(spaces == 1){
        ans += interruptsChain[found];
      }
    }
  }
                                                                              /*HTML instructions*/

  cout << "<center>";
    cout << "<h1>Información del Sistema</h1>" << endl;
    
    cout << "<h2>Número de núcleos</h2>" << endl;
    cout << "<tr><td>" << "La cantidad de procesadores del sistema es de " << cores << "." << "</td></tr>";
    cout << "<br>";
    cout << "<h2>Cantidad de procesos corriendo</h2>" << endl;
    cout << "<tr><td>" << "La cantidad de procesos corriendo en el sistema es de " << processes << "." << "</td></tr>";
    cout << "<br>";
    cout << "<h2>Memoria RAM</h2>" << endl;
    cout << "<tr><td>" << "La cantidad de memoria RAM total en el sistema es de " << totalRAM << "." << "</td></tr>";
    cout << "<br>";
    cout << "<h2>Memoria RAM Disponible</h2>" << endl;
    cout << "<tr><td>" << "La cantidad de memoria RAM disponible en el sistema es de " << availableRAM << "." << "</td></tr>";
    cout << "<br>";
    cout << "<h2>Cantidad de Interrupciones</h2>" << endl;
    cout << "<tr><td>" << "La cantidad total de interrupciones ejecutadas es de " << ans << "." << "</td></tr>";    
  cout << "</center>";


  
  
  cout << "</body>" << endl;
  cout << "</html>" << endl;

  return 0;
}