#include <stdio.h>

const int tsize = 10000;

void printbyte(char znak){
	int value;
	int i;
	for(i = 7; i >= 0; i--){
		value = znak >> i;
		value = value & 1;
		printf("%i", value);
	}
}

>>
<<
~
&
|
^


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
	
	i = 0;
	while(i < tsize && tekst[i] != EOF){
		printbyte(tekst[i]);
		printf("\n");
		i++;
	}
	
	return 0;
}
