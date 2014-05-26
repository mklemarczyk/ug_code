#include <stdio.h>

const int tsize = 10000;
int rsize = 0;

void drukujliczbe(int liczba){
	printf("%x", liczba);
}

void szyfruj(char* tekst){
	int dane = 0;
	int i = 0;
	while(i < tsize && tekst[i] != EOF){
		if(i % 4 == 0 && i != 0){
			drukujliczbe(-dane);
			printf("\n");
			dane = 0;
		}
		
		dane = dane << 8;
		dane = dane|((int)tekst[i]);
		
		i++;
	}
	if(dane != 0){
		drukujliczbe(-dane);
		printf("\n");
	}
}

int main(){
	char tekst[tsize];
	char znak;
	int i;
	
	i = 0;
	do{
		znak = getchar();		
		tekst[i] = znak;
		i++;
	}while(znak != EOF);
	tekst[i] = EOF;
	rsize = i-1;
	
	szyfruj(tekst);
	
	return 0;
}
