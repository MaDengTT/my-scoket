#include"wrap.h"
#include<pthread.h>
#define MAXLINE 4096
#define DEFAULT_PORT 8666


void* service_thread(void* p){
    int fd = *(int*)p;
    char str[MAXLINE];
    while(1){
        if(Read(fd,str,sizeof(str))){
            printf("LOG: %d\t%s\n",fd,str);
            Write(fd,str,sizeof(str));
        }
    }

}

int main(int argc, char const *argv[])
{
    
    int serv_sock;

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port = htons(DEFAULT_PORT);

    serv_sock = Scoket(AF_INET,SOCK_STREAM,0);

    Bind(serv_sock,(struct scokaddr*)&serv_addr,sizeof(serv_addr));

    Listen(serv_sock,10);

    while(1){
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int clnt_sokc = accept(serv_sock,(struct scokaddr*)&clnt_addr,clnt_addr_size);
        char str[]="Hello MM";
        send(clnt_sokc,str,sizeof(str),0);
       
    }

    return 0;
}
