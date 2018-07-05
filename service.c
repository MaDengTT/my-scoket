#include"service.h"
#include<stdlib.h>
struct Message
{
    int i;
    char* str;
};


message *new_Message()
{
    message *new_Message_ = (message *)malloc(sizeof(message));
    return new_Message_;
}

void free_Message(message* message_)
{
    if(message_!=NULL)
    {
        free(message_);
    }
    return;
}
