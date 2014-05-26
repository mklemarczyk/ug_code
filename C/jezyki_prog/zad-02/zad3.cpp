#include <stdio.h>

const int tsize = 10000;
int rsize = 0;

void drukujznak(char znak){
	printf("%c", znak);
}

void odszyfruj(char* tekst){
	int dane = 0;
	int i = 0;
	int pos = 0;
	while(i < tsize && tekst[i] != EOF){
		if(tekst[i] == '\n'){
			dane = 0;
			pos = 0;
		}else{
			if(pos == 2){
				drukujznak(-dane);
				dane = 0;
				pos = 0;
			}
			int liczba = (int)tekst[i];
			dane = dane << pos * 8;
			dane = dane | liczba;
			pos++;
		}
		i++;
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
	
	odszyfruj(tekst);
	
	return 0;
}
