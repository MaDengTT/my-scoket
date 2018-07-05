#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<signal.h>
//#include"socketUtils.c"
#include"threadpool.h"
#define MAXLINE 4096
#define DEFAULT_PORT 8666
struct threadpool* pool;


void logi(int code,char* args)
{
    if(code == 1){
        printf("succee:\t%s\n",args);
    }else if(code == -1){
        printf("error:\t%s\n",args);
    }else{
        printf("%s\n",args);
    }
}

void* service_thread(void* p){
    int fd = *(int*)p;
    char str[] = "Hello World! you is:";
    char strCat[100];
    sprintf(strCat,"%s%d",str,fd);
    send(fd,strCat,sizeof(strCat),0);
    char buff[MAXLINE];
    while(1){
        if(recv(fd,buff,sizeof(buff),0)>=0){
            printf("%d:%s\n",fd,buff);
            if((send(fd,buff,sizeof(buff),0))==-1){
                close(fd);
                break;
            }
        }
        memset(buff,0,sizeof(str));
    }
}


int initScoker(int port){
    // create = -1 error
    int serv_sock = socket(AF_INET,SOCK_STREAM,0);
    
    if(serv_sock == -1){
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //ipv4
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);//localhost
    serv_addr.sin_port = htons(port);

    if((bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)))==-1){
        return -1;
    }

    if((listen(serv_sock,10))==-1){
        return -1;
    }
    return serv_sock;
}
int main(int argc, char const *argv[])
{

    signal(SIGPIPE,SIG_IGN);

    pool = threadpool_init(10,20);

    int fds[100];
    int size = 100;

    int serv_sock = initScoker(DEFAULT_PORT);


    while(1){
       logi(1,"Accept socket...");
        //连接
        struct sockaddr_in clnt_addr;
        socklen_t clnt_addr_size = sizeof(clnt_addr);
        int clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
        if(clnt_sock == -1){
            logi(-1,"Accept socket...");
        }
        threadpool_add_job(pool,service_thread,&clnt_sock);
        // int i = 0;
        // for(i = 0;i<size;i++){
        //     if(fds[i] == 0){
        //         fds[i] = clnt_sock;
        //         printf("Accept socket == %d\n",clnt_sock);
        //         // pthread_t tid;
        //         // pthread_create(&tid,0,service_thread,&clnt_sock);
        //         break;
        //     }
        // }
    }

   

    // //接收
    // char buff[MAXLINE];
    // int n = recv(clnt_sock,buff,MAXLINE,0);
    // logi(0,"Recv:");
    // logi(0,buff);
    // //发送
    // char str[] = "Hello World!\n";
    // send(clnt_sock,str,sizeof(str),0);

    // logi(1,"Close socket...");
    // close(clnt_sock);
    // close(serv_sock);
    
    return 0;
}
