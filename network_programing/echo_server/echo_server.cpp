/*
 * =====================================================================================
 *
 *       Filename:  echo_server.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/02/2019 11:37:49
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
#include <string.h>
#include <errno.h>

#include <unistd.h>

#define SERVER_PORT 666
#define SERVER_IP "0.0.0.0"

void perror_exit(const char *des) {
//    fprintf(stderr, "%s error, reson:%s\n", des, strerror(errno));
    perror(des);
    exit(1);
}

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock==-1) {
        perror_exit("create socket");
    }

    sockaddr_in server_addr;

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr.s_addr);
    // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if(-1==bind(sock, (sockaddr*)&server_addr, sizeof(server_addr))) {
        close(sock);
        perror_exit("bind socket");
    }

    if(-1==listen(sock, 128)) {
        close(sock);
        perror_exit("listen");
    }

    printf("waiting...\n");

    int done = 1;

    while(done) {
        sockaddr_in client;
        int client_sock;

        char client_ip[64];
        char buf[256];
        memset(buf, '1', sizeof(buf));

        socklen_t client_addr_len;
        client_addr_len = sizeof(client);

        client_sock = accept(sock, (sockaddr*)&client, &client_addr_len);

        printf("client ip:%s,\tport:%d\n",
                inet_ntop(AF_INET, &client.sin_addr, client_ip, sizeof(client_ip)),
                ntohs(client.sin_port));

        int len = read(client_sock, buf, sizeof(buf)-1);
        buf[len] = '\0';

        printf("receive[%d]:%s", len, buf);

        for(int i=0; i<len; i++) { buf[i] = toupper(buf[i]); }

        len = write(client_sock, buf, len);

        printf("write finished. len:%d\n\n", len);
        close(client_sock);
    }

}
