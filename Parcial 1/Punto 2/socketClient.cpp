#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 4444

int main(){
  // - - - - - - -
  int clientSocket;
  struct sockaddr_in serverAddr;
  string buffer;
  char c[1024];

  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  
  if(clientSocket < 0){
    cout << "- - -| Error en la conexión |- - -" << endl;
    exit(1);
  }
  else{
    cout << "- - -| Cliente ha sido creado satisfactoriamente |- - -" << endl;
    
    memset(&serverAddr, '\0', sizeof(serverAddr)); //Toma la estructura y la inicia o llena de 0's lógicos (Null)

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    
    if(ret < 0){
      cout << "- - -| Error en la conexión |- - -" << endl;
      exit(1);
    }
    else{
      cout << "- - -| Se ha conectado al servidor satisfactoriamente |- - -" << endl;

      while(1){
        cout << "Cliente:\t";
        cin >> buffer;
        strcpy(c, buffer.c_str());
        send(clientSocket, c, strlen(c), 0);

        if(buffer == "salir"){
          close(clientSocket);
          cout << "- - -| Desconectado del servidor |- - -" << endl;
          exit(1);
        }
        else{
          strcpy(c, buffer.c_str());
          if( recv(clientSocket, c, strlen(c), 0) < 0){
            cout << "- - -| Error al recibir los datos |- - -" << endl;
          }
          else{
            cout << "Server:\t" << c << endl;
          }
        }
      }
    }
  }

  return 0;
}

