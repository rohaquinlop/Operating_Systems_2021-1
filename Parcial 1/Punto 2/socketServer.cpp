#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

#define PORT 4444

int main(){
  int sockfd, ret, newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_in newAddr;

  socklen_t addr_size;

  char c[1024];

  pid_t child;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0){
    cout << "- - -| Error en la conexión |- - -" << endl;
    exit(1);
  }
  else{
    cout << "- - -| Servidor creado satisfactoriamente |- - -" << endl;
    memset(&serverAddr, '\0', sizeof(serverAddr)); //Toma la estructura y la inicia o llena de 0's lógicos (Null)

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Conectar al servidor
    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    if(ret < 0){
      cout << "- - -| Error en la vinculación |- - -" << endl;
      exit(1);
    }
    else{
      cout << "- - -| Vinculado al puerto: " << PORT << "|- - -" << endl;

      if( listen(sockfd, 10) == 0 ){
        cout << "Escuchando..." << endl;
      }
      else{
        cout << "- - -| Error en la vinculación |- - -" << endl;
      }


      while(1){
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0)
          exit(1);
        else{
          cout << "Conexión satisfactoria de " << inet_ntoa(newAddr.sin_addr) << ":" << ntohs(newAddr.sin_port) << endl;

          child = fork();
          if(child == 0){
            close(sockfd);

            while(1){
              recv(newSocket, c, 1024, 0);
              string buffer(c);
              if(buffer == "salir"){
                cout << "Conexión finalizada satisfactoriamente de " << inet_ntoa(newAddr.sin_addr) << ":" << ntohs(newAddr.sin_port) << endl;
                break;
              }
              else{
                cout << "Cliente: " << buffer << endl;
                strcpy(c, buffer.c_str());
                send(newSocket, c, strlen(c), 0);
                bzero(c, sizeof(c));
              }
            }
          }
        }
      }
    }
  }

  close(newSocket);

  return 0;
}

