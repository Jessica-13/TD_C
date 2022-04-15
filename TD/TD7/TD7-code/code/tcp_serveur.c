// on crée un Socket
// fonction SetSockOpt : pour verifier que tout va bien
// Bind : pour faire le lien avec la machine
// Listen : attendre les clients potentiels et dire quand il y en a
// Accept : on regarde l'@IP de l'ordinateur qui nous démande
// -> on crée une Socket pour ce client
// Send/Reciv : une fois qu'on a la connexion on peut s'énvoyer des trucs

//# netstat -tupln : pour regarder quelles portees sont ouvertes sur notre machine 
//# netstat -t : liste toutes le socket tcp ouvertes sur votre machine
//# nc : net cat... vérifier que le client marche bien 

/* !!!
ntoh(); : network to host
hton(); : inverse

ntons();
ntohl();

((sont les fonctions qui vont faire la conversion pour un unsigned short ou
un unsigned int de l’ordre des octets.))
*/

// les paquets qui circulent sur le réseau sont en big endian
/* L’orientation gros-boutiste (big endian) : 
qui démarre avec les octets de poids forts
et l’orientation inverse petit-boutiste (little endian).*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>



int main(int argc, char *argv[])
{
    int sock_serv; 
    int sock_len=sizeof(struct sockaddr_in);
    struct sockaddr_in listen_addr;
    
    /* Creation de la socket */ 
    if ((sock_serv=socket(AF_INET,SOCK_STREAM,0)) == -1)
      {
	perror("Creation de socket impossible"); 
	return -1; 
      } 
    
    /* Preparation de l'adresse d'attachement: 
       l'adresse sur laquelle nous allons nous connecter */ 
    listen_addr.sin_family=AF_INET;
    
    /* Adresse: localhost, on suppose que le serveur est sur la machine 
       Attention: Conversion (interne) -> (reseau) avec htonl et htons 
       On écoute sur le port 20000 */
    listen_addr.sin_addr.s_addr=htonl(INADDR_ANY);  // Pour écouter
    listen_addr.sin_port=htons(20000);
    
    // appels
    bind(sock_serv,(struct sockaddr*)&listen_addr,sock_len);
    listen(sock_serv, 1);
    int socket_service;
    socklen_t sock_serv_len=sizeof(struct sockaddr_in);
    socket_service=accept(sock_serv,(struct sockaddr*) &listen_addr, &sock_serv_len);       //seulement pour ce client
    
    printf("Connection accepted on port number %d\n", ntohs(listen_addr.sin_port));
    printf("IP Address=%u.%u.%u.%u\n",(uint8_t)((listen_addr.sin_addr.s_addr>>24)&255),(uint8_t)((listen_addr.sin_addr.s_addr>>16)&255),(uint8_t)((listen_addr.sin_addr.s_addr>>8)&255),(uint8_t)(listen_addr.sin_addr.s_addr&255));
    //printf("Connection OK\n");

    char buffer[30];
    char mex[30];
    memset(buffer, 0, sizeof(buffer));
    strcpy(mex,"mex sent");

    recv(socket_service, buffer, sizeof(buffer),0);
    
    printf("Message : %s\n",buffer);

    for(int i = 0; i<3; i++)
    {
        send(socket_service, mex, sizeof(mex),0);
        recv(socket_service, buffer, sizeof(buffer), 0);
        printf("Message reçu serveur: %s\n",buffer);
    }

    return 0;
    
}