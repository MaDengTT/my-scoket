#ifndef WRAP_H
#define WRAP_H
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#include<arpa/inet.h>
#include<errno.h>

void perr_exit(const char *s);
int Accept(int fd,struct sockaddr *sz,socklen_t *salenptr);
void Bind(int fd,struct sockaddr* sa,socklen_t salen);
void Connect(int fd,struct sockaddr *sa,socklen_t salen);
void Listen(int fd,int backlog);
int Scoket(int family,int type,int protocol);
ssize_t Read(int fd,void *ptr,size_t nbytes);
ssize_t Write(int fd,void *ptr,size_t nbytes);
ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Writen(int fd, const void *vptr, size_t n);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
void Close(int fd);
#endif