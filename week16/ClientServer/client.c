#include <stdio.h>
#include <string.h> // strlen()
#include <unistd.h> // write(), read()
#include <stdlib.h> // exit(), atoi()
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // port number from command-line args
    int portno = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        error("ERROR opening socket");
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) 
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // setup server information
    struct sockaddr_in serv_addr;
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // establish server connection
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    {
        error("ERROR connecting");
    }

    // Ask user to input message
    char buffer[256];
    memset(buffer, 0, 255);
    printf("Please enter the message: ");
    fgets(buffer,255,stdin);

    // Send message to server
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
    {
        error("ERROR writing to socket");
    }

    // Receive reply from server
    memset(buffer, 0, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) 
    {
        error("ERROR reading from socket");
    }
    printf("%s\n",buffer);

    return 0;
}
