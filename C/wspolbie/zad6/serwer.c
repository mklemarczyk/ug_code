#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include "komunikaty.h"

#include <string.h>

typedef struct Fraza {
	char pl_text[DCOUNT];
	char en_text[DCOUNT];
} Fraza;

Fraza dane[20];

wstaw(int i, const char* textpl, const char* texten){
	Fraza item;
	strcpy(item.pl_text, textpl);
	strcpy(item.en_text, texten);
	dane[i] = item;
}

init_dane(){
	wstaw(0, "mleko", "milk");
	wstaw(1, "herbata", "tea");
	wstaw(2, "kawa", "coffe");
	wstaw(3, "komputer", "computer");
	wstaw(4, "laptop", "laptop");
	wstaw(5, "dom", "home");
	wstaw(6, "droga", "path");
	wstaw(7, "siec", "network");
	wstaw(8, "drzewo", "tree");
	wstaw(9, "lisc", "leaf");
	wstaw(10, "miecz", "sword");
	wstaw(11, "wlosy", "hair");
	wstaw(12, "ogien", "fire");
	wstaw(13, "swiatlo", "light");
	wstaw(14, "zasilanie", "power");
	wstaw(15, "bateria", "battery");
	wstaw(16, "ptak", "bird");
	wstaw(17, "kwiat", "flower");
	wstaw(18, "projektor", "projector");
	wstaw(19, "slonce", "sun");
}

main(){
	init_dane();
	
	struct komunikat kom;
	int kolejka1, kolejka2;
	int num = 0;

	kolejka1 = msgget(KEY1, 0777 | IPC_CREAT);
	kolejka2 = msgget(KEY2, 0777 | IPC_CREAT);
	while(1){
		msgrcv(kolejka1, &kom, DCOUNT, 0, 0);

		int i, found;
		found = -1;
		for(i = 0; i < 20; i++){
			// Str cmp nie potrafi obslugiwac char* :(
			if(strcmp(dane[i].en_text, kom.dane) == 0)
				found = i;
		}

		if(found > -1){
			memset(kom.dane, '\0', DCOUNT);
			strcpy(kom.dane, dane[found].pl_text);
			msgsnd(kolejka2, &kom, DCOUNT, 0);
		}else{
			const char* error_msg = "Nie znaleziono";
			memset(kom.dane, '\0', DCOUNT);
			strcpy(kom.dane, error_msg);
			msgsnd(kolejka2, &kom, DCOUNT, 0);
		}
	}
	msgctl(kolejka2, IPC_RMID, 0);
	msgctl(kolejka1, IPC_RMID, 0);
}
