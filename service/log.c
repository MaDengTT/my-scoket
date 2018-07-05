#include<stdio.h>

void log(int,char*);

void log(int code,char* args)
{
    if(code == 1){
        printf("succee:\t%s\n",args);
    }else if(code == -1){
        printf("error:\t%s\n",args);
    }else{
        printf("%s\n",args);
    }
}