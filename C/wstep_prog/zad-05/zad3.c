#include <stdio.h>

void main(){
	int s = 0;
	int i;
	int j;
	int n;
	
	printf("Podaj dlugosc: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		
		int p = i;
		
		for(j=1; j<i; j++){
			p = i*p;
		}
		
		s=s+p;
	}
	
	printf("Wynik: %d\n", s);
}

/*
Napisać i uruchomić program w C, który wczytuje liczbę naturalną n i drukuje sumę potęg

    11 + 22 + 33 + . . . + nn 

Wskazówka:
Potrzebne jest zagnieżdżenie pętli for. Zewnętrzna pętla powinna dodawać do sumy kolejny składnik. Wewnętrzna powinna wyliczać potęgę ii dla kolejnych i od 1 do n . 
*/
