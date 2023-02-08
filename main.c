#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int port, s = 0;
    port = atoi("7878");
    char *ipaddress;
    struct sockaddr_in serv_addr;
    char buffer[1024] = "Hello world";
    ipaddress = "192.168.1.2";

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (!inet_aton(ipaddress, &serv_addr.sin_addr)){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    else
        printf("Attempting to create socket. \n");

    s = socket(AF_INET, SOCK_STREAM, 0);
    // Creating socket
    if (!s){
        perror("Error: Could not create socket");
        exit(0);
    }
    else {
        printf("Socket Created. \n");
    }

    if (connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(s, buffer, sizeof(buffer), 1024);
    printf("%s\n",buffer);
    return 0;
}