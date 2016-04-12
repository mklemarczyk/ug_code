#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "komunikaty.h"

int main(){
	int a, fd;
	KlientMsg msg1;
	SerwerMsg msg2;
	const char* home = getenv("HOME");

	mkfifo("klientfifo", 0777);

	if((fd = open("serwerfifo", O_WRONLY, 0)) == -1){
		printf("Blad otwarcia serwerfifo\n");
		exit(0);
	}
	printf("Podaj id: ");
	scanf("%3d", &a);
	msg1.id = a;
	msg1.size = strlen(home);
	if(write(fd, &msg1, sizeof(msg1)) == -1){
		printf("Blad nadania dlugosci\n");
		exit(0);
	}
	if(write(fd, home, msg1.size) == -1){
		printf("Blad nadania powrotu\n");
		exit(0);
	}
	close(fd);

	fd = open("klientfifo", O_RDONLY, 0);
	if(read(fd, &msg2, sizeof(msg2)) == -1){
		printf("Blad odczytu dlugosci\n");
		exit(0);
	}
	char* tekst = (char*) malloc(msg2.size);
	if(read(fd, tekst, msg2.size) == -1){
		printf("Blad odczytu wiadomosci zwrotnej\n");
		exit(0);
	}

	printf("Odpowiedz: %s\n", tekst);

	close(fd);
	
	unlink("klientfifo");
}
