/**
 * @file server.c
 * @author NIC CS270
 * @brief A simple server in the internet domain using TCP
 *        The port number is passed as an argument
 * @version 0.1
 * @date 2020-12-10
 * 
 */
#include <stdio.h>
#include <string.h> // memset()
#include <stdlib.h> // exit(), atoi()
#include <unistd.h> // write(), read()
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        error("ERROR opening socket");
    }

    // port number from command-line args
    int portno = atoi(argv[1]);             

    // setup server information
    struct sockaddr_in serv_addr;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;         // AF_INET => TCP/IP protocol
    serv_addr.sin_addr.s_addr = INADDR_ANY; // socket will be bound to all local interfaces
    serv_addr.sin_port = htons(portno);     // set port number

    // bind a socket to a socket address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
    {
        error("ERROR on binding");
    }
    // listen indicates socket is ready to accept incoming connections
    listen(sockfd, 5);

    // use to store client's IP and port
    struct sockaddr_in cli_addr;
    int clilen = sizeof(cli_addr);

    // accept() blocks the caller until a connection is present
    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
    {
        error("ERROR on accept");
    }

    // Read data from clients
    char buffer[256];
    memset(buffer, 0, 256); // Why zero-out the buffer?
    int n = read(newsockfd, buffer, 255);
    if (n < 0) 
    {
        error("ERROR reading from socket");
    }

    printf("Here is the message: %s\n", buffer);

    // Reply back a message to the client (Confirmation)
    n = write(newsockfd, "I got your message", 18);
    
    if (n < 0)
    {
        error("ERROR writing to socket");
    }

    return 0; 
}
