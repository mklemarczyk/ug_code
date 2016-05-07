#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include "komunikaty.h"

#include <string.h>

main(){
	struct komunikat kom;
	int kolejka1, kolejka2;
	long ident;
      
	kolejka1 = msgget(KEY1, 0777);
	kolejka2 = msgget(KEY2, 0777);
	ident = getpid();
	kom.mtype = ident;

	memset(kom.dane, '\0', DCOUNT);
	printf("Podaj slowo do tlumaczenia(EN): ");
	scanf("%s", kom.dane);

	msgsnd(kolejka1, &kom, DCOUNT, 0);

	memset(kom.dane, '\0', DCOUNT);
	msgrcv(kolejka2, &kom, DCOUNT, ident, 0);
	printf("Tlumaczenie(PL) to: %s\n", ident, kom.dane);
}
