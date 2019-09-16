/*
 * =====================================================================================
 *
 *       Filename:  echo_client.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/03/2019 14:37:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 666
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd;
    char *message;
    int n = 0;
    char buf[256];

    sockaddr_in servaddr;
    bzero(&servaddr, sizeof(sockaddr_in));

    if(argc!=2) {
        fputs("Usage: ./echo_client message \n", stderr);
        exit(1);
    }

    message = argv[1];
    printf("send message:%s\n", message);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERVER_PORT);

    connect(sockfd, (sockaddr*)&servaddr, sizeof(sockaddr_in));

    write(sockfd, message, strlen(message) );


    if ( read(sockfd, buf, sizeof(buf)-1) > 0 ) {
        printf("received:%s\n", buf);
    } else {
        perror("error!!!!");
    }

    printf("finished.\n");

    close(sockfd);
}
