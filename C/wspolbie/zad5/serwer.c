#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "komunikaty.h"

typedef struct Rekord {
	int id;
	int size;
	char* msg;
} Rekord;

Rekord dane[20];

wstaw(int i, int id, const char* msg){
	Rekord item;
	item.id = i;
	item.size = strlen(msg);
	item.msg = (char*) malloc(item.size);
	memcpy(item.msg, msg, item.size);
	dane[i] = item;
}

init_dane(){
	wstaw(0, 1, "GorgeA");
	wstaw(1, 2, "GorgeB");
	wstaw(2, 3, "GorgeC");
	wstaw(3, 4, "GorgeD");
	wstaw(4, 5, "GorgeE");
	wstaw(5, 6, "GorgeF");
	wstaw(6, 7, "GorgeG");
	wstaw(7, 8, "GorgeH");
	wstaw(8, 9, "GorgeI");
	wstaw(9, 10, "GorgeJ");
	wstaw(10, 11, "GorgeK");
	wstaw(11, 12, "GorgeL");
	wstaw(12, 13, "GorgeM");
	wstaw(13, 14, "GorgeN");
	wstaw(14, 15, "GorgeO");
	wstaw(15, 16, "GorgeP");
	wstaw(16, 17, "GorgeR");
	wstaw(17, 18, "GorgeS");
	wstaw(18, 19, "GorgeT");
	wstaw(19, 20, "GorgeU");
}

main(){
	int fd1, fd2;
	KlientMsg msg1;
	SerwerMsg msg2;

	init_dane();

	unlink("serwerfifo");
	mkfifo("serwerfifo", 0777);
	
	while((fd1 = open("serwerfifo", O_RDONLY, 0)) != -1){
		if(read(fd1, &msg1, sizeof(msg1)) == -1){
			printf("Blad odczytu wiadomosci\n");
			exit(0);
		}

		char* homePath = (char*) malloc(msg1.size);
		if(read(fd1, homePath, msg1.size) == -1){
			printf("Blad odczytu katalogu powrotu\n");
			exit(0);
		}

		int i, found;
		found = -1;
		for(i = 0; i < 20; i++){
			if(dane[i].id == msg1.id)
				found = i;
		}

		if((fd2 = open("klientfifo", O_WRONLY, 0)) != -1){
			if(found > -1){
				msg2.size = dane[found].size;
				if(write(fd2, &msg2, 4) == -1){
					printf("Blad wyslania dlugosci\n");
					exit(0);
				}
				if(write(fd2, dane[found].msg, msg2.size) == -1){
					printf("Blad wyslania wiadomosci\n");
					exit(0);
				}
			}else{
				const char* error_msg = "Nie znaleziono";
				msg2.size = strlen(error_msg);
				if(write(fd2, &msg2, 4) == -1){
					printf("Blad wyslania dlugosci\n");
					exit(0);
				}
				if(write(fd2, error_msg, msg2.size) == -1){
					printf("Blad wyslania wiadomosci\n");
					exit(0);
				}
			}
			close(fd2);
		}else{
			printf("Blad otwarcia powrotu\n");
			exit(0);
		}
		close(fd1);
	}

	printf("Koniec dzialania\n");
}
