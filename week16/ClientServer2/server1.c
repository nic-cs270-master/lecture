/* Single server-client connection; server can talk to only
 * one client at a time (pgs 244-246) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>   /* system type defintions        */
#include <sys/socket.h>  /* network system functions      */
#include <netinet/in.h>  /* protocol & struct definitions */

#define BUF_SIZE     1024
#define LISTEN_PORT  6000

int main( int argc, char *argv[] )
{
    int              sock_listen, sock_recv;
    struct sockaddr_in  my_addr, recv_addr;
    int              i, bytes_received;
    size_t           addr_size;
    fd_set           readfds;
    /*BB: org int              i, addr_size, bytes_received;
    /*BB: org struct timeval   timeout = {0,0}; not used*/
    int              incoming_len, recv_msg_size;
    struct sockaddr  remote_addr;
    char             buf[BUF_SIZE];
    int              select_ret;

    /* create socket for listening */
    sock_listen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_listen < 0) {
        printf("socket() failed\n");
        exit(0);
    }

    /* make local address structure */
    memset(&my_addr, 0, sizeof(my_addr));         /* zero out structure */
    my_addr.sin_family = AF_INET;                 /* address family */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP */
    my_addr.sin_port = htons((unsigned short)LISTEN_PORT);

    /* bind socket to the local address */
    i = bind(sock_listen, (struct sockaddr *) &my_addr, sizeof(my_addr));
    if (i < 0)
    {
        printf("bind() failed\n");
        exit(0);
    }
    /* listen ... */
    i = listen(sock_listen, 5);
    if (i < 0)
    {
        printf("listen() failed\n");
        exit(0);
    }

    /* get new socket to receive data on */
    addr_size = sizeof(recv_addr);
    sock_recv = accept(sock_listen, (struct sockaddr *) &recv_addr, &addr_size);

    while (1)
    {
        bytes_received = recv(sock_recv,buf,BUF_SIZE,0);
        buf[bytes_received] = 0;
        printf( "Received: %s\n", buf );
        if (strcmp(buf,"shutdown") == 0)
        break;
    }

    close(sock_recv);
    close(sock_listen);
}
