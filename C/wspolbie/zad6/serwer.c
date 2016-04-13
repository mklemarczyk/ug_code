#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include "komunikaty.h"

#include <string.h>

typedef struct Fraza {
	char* pl_text;
	char* en_text;
} Fraza;

Fraza dane[20];

wstaw(int i, const char* textpl, const char* texten){
	Fraza item;

	int pl_len = strlen(textpl);
	item.pl_text = (char*) malloc(pl_len);
	memcpy(item.pl_text, textpl, pl_len);

	int en_len = strlen(texten);
	item.en_text = (char*) malloc(en_len);
	memcpy(item.en_text, texten, en_len);

	dane[i] = item;
}

init_dane(){
	wstaw(0, "GorgeA", "GorgeA");
	wstaw(1, "GorgeA", "GorgeB");
	wstaw(2, "GorgeA", "GorgeC");
	wstaw(3, "GorgeA", "GorgeD");
	wstaw(4, "GorgeA", "GorgeE");
	wstaw(5, "GorgeA", "GorgeF");
	wstaw(6, "GorgeA", "GorgeG");
	wstaw(7, "GorgeA", "GorgeH");
	wstaw(8, "GorgeA", "GorgeI");
	wstaw(9, "GorgeA", "GorgeJ");
	wstaw(10, "GorgeA", "GorgeK");
	wstaw(11, "GorgeA", "GorgeL");
	wstaw(12, "GorgeA", "GorgeM");
	wstaw(13, "GorgeA", "GorgeN");
	wstaw(14, "GorgeA", "GorgeO");
	wstaw(15, "GorgeA", "GorgeP");
	wstaw(16, "GorgeA", "GorgeR");
	wstaw(17, "GorgeA", "GorgeS");
	wstaw(18, "GorgeA", "GorgeT");
	wstaw(19, "GorgeA", "GorgeU");
}

main(){
	init_dane();
	
	struct komunikat kom;
	int kolejka1, kolejka2, *wsk;
	int num = 0;

	kolejka1 = msgget(KEY1, 0777 | IPC_CREAT);
	kolejka2 = msgget(KEY2, 0777 | IPC_CREAT);
	while(1){
		msgrcv(kolejka1, &kom, sizeof(int), 0, 0);
		wsk = (int*) kom.dane;
		printf("serwer: otrzymalem %5d od %5ld\n", *wsk, kom.mtype);
		(*wsk) += num;
		num++;
		printf("serwer: odsylam %5d do %5ld\n", *wsk, kom.mtype);
		msgsnd(kolejka2, &kom, sizeof(int), 0);
		if(num >= 3){
			break;
		}
	}
	msgctl(kolejka2, IPC_RMID, 0);
	msgctl(kolejka1, IPC_RMID, 0);
}
