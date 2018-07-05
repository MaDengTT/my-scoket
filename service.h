#ifndef SERVICE_H
#define SERVICE_H

struct Message;

typedef struct Message message;

message *new_Message();
void free_Message(message *message_);

#endif