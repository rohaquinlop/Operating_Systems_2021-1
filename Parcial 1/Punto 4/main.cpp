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
    int f = fork();
    if( f < 0){
      cout << "- - -| Ha ocurrido un erorr al ejecutar el fork |- - -" << endl;
    }
    else if( f == 0){
      close(fd[0]);
      //Es el hijo
      //Leer el directorio, luego tomar los archivos del directorio (*.c, *.h)
      // ls -la *.c *.h

      cout << "Ingrese el directorio #1:\t";
      cin >> dir0;
      write(fd[1], dir0.c_str(), dir0.length()+1);

      cout << "Ingrese el directorio #2:\t";
      cin >> dir1;
      write(fd[1], dir1.c_str(), dir1.length()+1);
      
      //Ejecutar el comando sobre el directorio #1
      string command = "cd " + dir0 + " && ls -la *.cpp";

      vector<string> ls = exec(command);

      for(string s : ls){
        write(fd[1], s.c_str(), s.length()+1);
      }

      /*
      for(int i = 0; i < 3; ++i){
        cout << getpid() << " i ->" << i << ": ";
        cin >> s;
        write(fd[1], &s, sizeof(s));
        //sleep(3);
      }
      */
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
          cout << getpid()  << " Salida:\t" << s << endl;
          //cout << s << endl;
          s = "";
        }
      }
      close(fd[0]);
    }
  }

  return 0;
}