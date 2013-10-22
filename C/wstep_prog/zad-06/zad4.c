#include <stdio.h>

void main(){
	char tab[30];
	int i = 0;
	int palindrom = 1;
	char litera = 'a';
	
	printf("Podaj slowo: ");
	while((int)litera != 10){ //sprawdzamy czy wciśnięto znak enter (ma kod ASCII 10)
		scanf("%c", &litera); // pobieramy litere
		if((int)litera != 10){
			tab[i] = litera;
			i++;
		}
	}
	
	int liczbaZnakow = i;

	for(i = 0; i<liczbaZnakow; i++){
		printf("%c", tab[i]);
		if(i<liczbaZnakow/2 && tab[i] != tab[liczbaZnakow-i-1])
			palindrom = 0;
	}

	if(palindrom == 1)
		printf(" .... jest palindromem\n");
	else
		printf(" .... nie jest palindromem\n");
}
