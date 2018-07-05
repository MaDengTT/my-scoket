#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<arpa/inet.h>



int initScoker(int DEFAULT_PORT){
    // create = -1 error
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);
    
    if(serv_sock == -1){
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //ipv4
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);//localhost
    serv_addr.sin_port = htons(DEFAULT_PORT);

    if((bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))==-1){
        return -1;
    }

    if((listen(serv_sock,10))==-1){
        return -1;
    }
    return serv_sock;
}
