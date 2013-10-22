//STATYSTYKA LITER W TEKSCIE

#include<stdio.h>
#include<stdlib.h>

#define DL_ALFABETU 26

void  blad (char komunikat[]) {
	printf("\n!!! BLAD -- %s!!!\n\n", komunikat);
	exit(1);
}

int  numer_litery (char litera) {
	// duze litery sa sklejane z malymi; nielitery uzyskuja numer -1
	if ('a' <= litera && litera <= 'z')
		return (int)litera - (int)'a';
	else
		if ('A'<=litera && litera<='Z')
			return (int)litera - (int)'A';
		else
			return -1;
}

char  litera_o_numerze (int n) {
	// jesli n<0 lub n>=DL_ALFABETU -- sygnal bledu
	if (0 <= n && n < DL_ALFABETU)
		return (char)((int)'a'+n);
	else
		blad("zly numer litery");
}

void posortuj (int dane[DL_ALFABETU], int wynik[DL_ALFABETU]){
	int i;
	int temp[DL_ALFABETU];
	
	for (i=0; i<DL_ALFABETU; i++){
		temp[i] = dane[i];
	}
	
	for (i=0; i<DL_ALFABETU; i++){
		int p;
		int max = 0;
		for(p=1; p<DL_ALFABETU; p++)
			if(temp[p] > temp[max])
				max = p;
		temp[max] = -1;
		wynik[i] = max;
	}
}

main () {
	char znak;
	int liczniki[DL_ALFABETU], i;
	int kolejnosc[DL_ALFABETU];

	// inicjalizacja licznikow:
	for (i=0; i<DL_ALFABETU; i++)  liczniki[i] = 0;

	// wczytywanie tekstu i zliczanie liter:
	znak = getchar();
	while (znak != EOF) {
		i = numer_litery(znak);
		if (i>=0)
			liczniki[i] = liczniki[i]+1;
		znak = getchar();
	}

	// drukowanie statystyki:
	printf("\nSTATYSTYKA wg liter:\n");
	for (i=0; i<DL_ALFABETU; i++)
		printf("  %c: %4i\n", litera_o_numerze(i), liczniki[i]);
	printf("\n");
	
	printf("\nSTATYSTYKA wg czestotliwosci:\n");
	posortuj(liczniki, kolejnosc);
	for (i=0; i<DL_ALFABETU; i++)
		printf("  %c: %4i\n", litera_o_numerze(kolejnosc[i]), liczniki[kolejnosc[i]]);
	printf("\n");
}
