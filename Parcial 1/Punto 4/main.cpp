#include <unistd.h>
#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;

vector<string> exec(string command) {
   char buffer[1024];
   vector<string> ans;
   string result = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return ans;
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 1024, pipe) != NULL){
        result = buffer;
        result.erase(remove(result.begin(), result.end(), '\n'), result.end());
        ans.push_back(result);
      }
   }

   pclose(pipe);
   return ans;
}

string exec1(string command){
   char buffer[1024];
   string ans = "";

   // Open pipe to file
   FILE* pipe = popen(command.c_str(), "r");
   if (!pipe) {
      return ans;
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 1024, pipe) != NULL){
        ans = buffer;
        ans.erase(remove(ans.begin(), ans.end(), '\n'), ans.end());
        return ans;
      }
   }

   pclose(pipe);
   return ans;
}

vector<string> parseInput(string s){
  vector<string> v;
  istringstream ss(s);
  string aux;

  while( ss >> aux ){
    v.push_back(aux);
  }

  return v;
}

int main(){
  int fd[2];
  string s, dir0, dir1;
  char buffer[1024];
  // fd[0] -> Lectura
  // fd[1] -> Escritura

  if( pipe(fd) == -1 ){
    cout << "- - -| Ha ocurrido un error al ejecutar pipe |- - -" << endl;
  }
  else{
    cout << "Ingrese el directorio #1:\t";
    cin >> dir0;
    //write(fd[1], dir0.c_str(), dir0.length()+1);

    cout << "Ingrese el directorio #2:\t";
    cin >> dir1;
    //write(fd[1], dir1.c_str(), dir1.length()+1);
    
    int f = fork();
    if( f < 0){
      cout << "- - -| Ha ocurrido un erorr al ejecutar el fork |- - -" << endl;
    }
    else if( f == 0){
      close(fd[0]);
      //Es el hijo
      //Leer el directorio, luego tomar los archivos del directorio (*.c, *.h)
      // ls -la *.c *.h
      
      //Ejecutar el comando sobre el directorio #1
      string command = "cd " + dir0 + " && ls -la *.c *.h";

      vector<string> ls = exec(command);

      for(string s : ls){
        write(fd[1], s.c_str(), s.length()+1);
      }

      close(fd[1]);
      wait(NULL);
    }
    else{
      //Es el padre
      close(fd[1]);
      char c;
      s = "";

      while( read(fd[0], &c, 1) > 0 ){
        //Lee hasta EOF
        if(c != 0){
          s += c;
        }
        else{
          if( s != "" ){
            vector<string> parseDir0 = parseInput(s);
            string fileName = parseDir0[parseDir0.size()-1];

            string command = exec1("cd " + dir1 + "&& ls -la " + fileName);

            if(command == ""){
              //No encontró el archivo en el segundo directorio

              string cp = "cp " + dir0 + "/" + fileName + " " + dir1;

              system((char*)cp.c_str());
            }
            else{
              //Encontró el archivo en el segundo directorio

              // Hay que comparar las fechas de modificación de ambos archivos, y si la fecha de modificación del archivo en el primer
              // directorio es más reciente que en el segundo directorio entonces se copia

              string condition = exec1("[ " + dir0 + "/" + fileName + " -nt " + dir1 + "/" + fileName + " ] && echo \"yes\"");

              if(condition == "yes"){
                //Se cumple que el archivo en el primer directorio es más reciente que el archivo en el segundo directorio

                //Se elimina el archivo en el segundo directorio y se copia el archivo del primer directorio al segundo directorio
                
                string cp ="rm "+ dir1 + "/" + fileName + " && cp " + dir0 + "/" + fileName + " " + dir1;
                system((char*)cp.c_str());
              }

            }
          }
          s = "";
        }
      }
      close(fd[0]);
    }
  }

  return 0;
}