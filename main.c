#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int MAX_MSG = 1024;
    printf("Starting");
    int SERVER_PORT = 7878;
    int sd, newSd, rc, i, cliSd, servLen, num, k, p;
    struct sockaddr_in servAddr;
    struct hostent *h;
    char si[4];
    char line[MAX_MSG];
    char message[MAX_MSG];
    struct  timeval tp;
    time_t now;
    char msg[MAX_MSG];
    char str[MAX_MSG];

    strcpy(msg, "Hello World");

    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr("192.168.1.2");
    servAddr.sin_port = htons(SERVER_PORT);

    /* create socket */
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd<0)
    {
        exit(1);
    }
    rc = -1;
    for (;rc!=0;)
    {
        /* connect to server */
        rc = connect(sd, (struct sockaddr *) &servAddr, sizeof(servAddr));
        if(rc<0)
        {
            sleep(2);
        }

    }

    memset(message, 0, sizeof(message));
    memset(si, 0, sizeof(si));
    num = strlen(msg);
    //integertostring(si, num, 4);
    memcpy(message, si, 4);
    memcpy(message + strlen(message), msg, strlen(msg));

    rc = send(sd, message, strlen(message), 0);
    if(rc<0)
    {
        close(sd);
        exit(1);

    }

    sleep(1);
    //read_line(sd,line);
    memset(line,0x0,MAX_MSG);

    return 1;
}