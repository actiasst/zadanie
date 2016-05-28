#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

struct mymsg{
long type;
char wiadomosc[20];
};

int main()
{
key_t key = 100;
int msqid = msgget(key,IPC_CREAT|0666);

struct mymsg msg;
char pom[20];
scanf("%s",pom);

msg.type = 3;
strcpy(msg.wiadomosc,pom);

if(msgsnd(msqid,(void*) &msg,sizeof(msg.wiadomosc),0)==-1)
perror("Blad");

return 0;
}
