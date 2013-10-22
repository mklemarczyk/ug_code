#include <stdio.h>

void main(){
	int a;
	printf("Podaj liczbe:");
	scanf("%d", &a);

	int s=1;
	int i;
	for(i = a-1; i>1; i--){
		if(a%i==0)
			s++;
	}
	
	printf("Liczba %d, ma %d podzielnikow!\n", a,s);
}

/*
 Zad z *
a) Napisz program który wypisuje liczbę podzielników liczby.
b) Napisz program który drukuje pierwsze 4 liczby które
są doskonałe czyli są sumą swoich podzielników.
Jakiego rodzaju petlę użyjesz w tym programie ?
Uwaga! do powyższego zadania trzeba użyć konstrukcji if ... else ...
Oto przykład takiego zastosowania: wypisujemy zmienną a jeśli
jest liczbą nieparzystą, oraz napis parzysta, w przeciwnym wypadku:
if ((a%2) == 1) {
printf("liczba %d jest nieparzysta",a);
} else {
printf("parzysta");
} 
Prosze zwrócic uwagę, że porównanie składa się z 2 znakow równości, w przeciwnym wypadku, będzie to przypisanie i zawsze prawdziwe. 
*/
