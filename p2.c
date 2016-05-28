#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct mymsg{
long type;
char wiadomosc[20];
};

int main()
{
int msq = msgget(100,IPC_CREAT|0666);

struct mymsg msg;

if(msgrcv(msq,(void *)&msg,sizeof(msg.wiadomosc),3,0) == -1)
perror("Blad");

int i = 0;
int licznik = 0;

for(i ; i < strlen(msg.wiadomosc) ; i++)
{
if( ((int)(msg.wiadomosc[i])<0) && ((int)(msg.wiadomosc[i])>127))
licznik++;
}

if( ( ((int)(msg.wiadomosc[0])<65) || ((int)(msg.wiadomosc[0])>90)  )&&(  ((int)(msg.wiadomosc[0])<97) || ((int)(msg.wiadomosc[0])>122) ) )
licznik++;


if(licznik == 0)
printf("%s\n",msg.wiadomosc);

return 0;
}
