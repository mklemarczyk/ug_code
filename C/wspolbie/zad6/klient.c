#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include "komunikaty.h"

#include <string.h>

main(){
	struct komunikat kom;
	int kolejka1, kolejka2, *wsk;
	long ident;
      
	kolejka1 = msgget(KEY1, 0777);
	kolejka2 = msgget(KEY2, 0777);
	ident = getpid();
	wsk = (int*) kom.dane;
	*wsk = 5;
	kom.mtype = ident;
	msgsnd(kolejka1, &kom, sizeof(int), 0);
	printf("klient %5ld wyslalem %5d\n", ident, *wsk);
	msgrcv(kolejka2, &kom, sizeof(int), ident, 0);
	printf("klient %5ld otrzymalem %5d\n", ident, *wsk);
}
