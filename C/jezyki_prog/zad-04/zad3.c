/*
Zdefiniuj typ osoba który będzie strukturą o nazwie str_os
o polach imie, nazwisko będącymi tablicami znaków o długości 20
oraz polach wiek (liczba całkowita short int) wzrost (tak samo)
oraz kolor_oczu o typie znakowym i wartościach będących literami
'z','b','n','s'.
Następnie zdefiniuj tablicę lista_osob długości 4 o elementach
typu osoba. Wypełnij pola tych 4ech struktur jakimiś danymi
W pętli przeglądając tablicę wypisz danych osób o wieku większym od
18 i koloru różnym od 'b'.
Uwaga: aby wpisać imię "Ala" do i-tego elementu tablicy (będącego strukturą str_os)
załącz plik nagłówkowy string.h oraz wykonaj operację:
strcpy(lista_osob[i].imie,"Ala"); czyli trzeba
użyć funkcji strcpy z biblioteki string.h
*/


#include<stdio.h>
#include<math.h>
#include<string.h>

typedef struct str_os {
	char imie[20];
	char nazwisko[20];
	short int wiek;
	short int wzrost;
	char kolor_oczu;
}  osoba;

void drukuj_osoba(osoba o){
	printf("Osoba: %s %s\n", o.nazwisko, o.imie);
	printf("wiek - %i, wzrost - %i\n", o.wiek, o.wzrost);
	printf("kolor oczu - ");
	switch(o.kolor_oczu){
		case 'z':
			printf("zielone");
			break;
		case 'b':
			printf("brazowe");
			break;
		case 'n':
			printf("niebieskie");
			break;
		case 's':
			printf("szary");
			break;
		case 'c':
			printf("czarny");
			break;
		default:
			printf("nieznany");
			break;
	}
	printf("\n");
	printf("\n");
}

int main () {
	osoba baza[4];
	
	/*memcpy(&baza[0].imie, "Marta", 20);
	memcpy(&baza[0].nazwisko, "Kowalska", 20);*/
	baza[0].wiek = 20;
	baza[0].wzrost = 178;
	baza[0].kolor_oczu = 'b';

	/*memcpy(&baza[1].imie, "Jan", 20);
	memcpy(&baza[1].nazwisko, "Kwiatkowski", 20);*/
	baza[1].wiek = 14;
	baza[1].wzrost = 152;
	baza[1].kolor_oczu = 'z';

	/*memcpy(&baza[2].imie, "Oktawia", 20);
	memcpy(&baza[2].nazwisko, "Tkacka", 20);*/
	baza[2].wiek = 41;
	baza[2].wzrost = 186;
	baza[2].kolor_oczu = 'n';

	/*memcpy(&baza[3].imie, "Filemon", 20);
	memcpy(&baza[3].nazwisko, "Podlasiak", 20);*/
	baza[3].wiek = 12;
	baza[3].wzrost = 135;
	baza[3].kolor_oczu = 's';

	int i;
	for(i = 0; i < 4; i++){
		printf("\nImie: ");
		scanf("%s", baza[i].imie);
		printf("Nazwisko: ");
		scanf("%s", baza[i].nazwisko);
	}
	
	printf("\n");

	for(i = 0; i < 4; i++){
		if(baza[i].wiek > 18 && baza[i].kolor_oczu != 'b')
			drukuj_osoba(baza[i]);
	}

	return 0;
}

