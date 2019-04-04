/*
 *
 * title: schn (Secure Content Hosting Network)
 * type: peer2peer network
 * auther: collin cole
 * e-mail: askcollincole@gmail.com
 *
 */

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*for later implementations*/
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>



#define SCHN_RECV_BUFFER_SIZE 1024

void
schn_loop()
{
	int create_socket, new_socket;
	socklen_t addrlen;
	char *buffer = malloc(SCHN_RECV_BUFFER_SIZE * sizeof(char));
	struct sockaddr_in address;

	if((create_socket = socket(AF_INET, SOCK_STREAM, 0)) > 0)
	{
		fprintf(stdout,"new Socket created\n");
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(1500);

	if (bind(create_socket, (struct sockaddr *) &address, sizeof(address)) == 0){    
      fprintf(stdout,"Binding Socket\n");
   }
    
    
   while (1) {    
      if (listen(create_socket, 10) < 0) {    
         fprintf(stderr,"server: listen");    
         exit(1);    
      }    
    
      if ((new_socket = accept(create_socket, (struct sockaddr *) &address, &addrlen)) < 0) {    
         fprintf(stderr,"server: accept");    
         exit(1);    
      }    
    
      if (new_socket > 0){    
         fprintf(stdout,"The Client is connected...\n");
      }
        
      recv(new_socket, buffer, SCHN_RECV_BUFFER_SIZE, 0);    
      fprintf(stdout,"%s\n", buffer);    
      write(new_socket, "hello world\n", 12);    
      close(new_socket);    
   }    
   close(create_socket);
   return;

}


int
main(int argc, char **argv)
{
	/* Initialization */

	/* Main */

	schn_loop();

	/* Termination */


	return 0;	
}
