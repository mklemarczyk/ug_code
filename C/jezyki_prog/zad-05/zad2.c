#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define IMIE_MAX 15
#define NAZW_MAX 15
#define IL_OSOB 11

typedef struct {
	char imie[IMIE_MAX+1];
	char nazwisko[NAZW_MAX+1];
	int pensja;
} osoba;

osoba spis[IL_OSOB];

//=======================================================

void utworz_spis(void) {
	FILE* baza = fopen("./lista","r");
	if (baza == NULL) printf("\n ZLE\n\n");
	int i;
	for (i = 0; i < IL_OSOB; i++) {
		fscanf(baza, "%s", spis[i].imie);
		fscanf(baza, "%s", spis[i].nazwisko);
		fscanf(baza, "%i", &spis[i].pensja);
	}
	fclose(baza);
}

//=======================================================

void swapos(osoba x[IL_OSOB], int n1, int n2){
	osoba tmp = x[n1];
	x[n1] = x[n2];
	x[n2] = tmp;
}

void sortuj_spis(void) {
	/* sortuje  spis  alfabetycznie wg nazwisk,
	 a w przypadku rownych nazwisk wg imion
	*/
	int i, j;
	for(i = 0; i < IL_OSOB; i++){
		for(j = 0; j < IL_OSOB; j++){
			if(strcmp(spis[i].nazwisko, spis[j].nazwisko) < 0){
				swapos(spis, i, j);
			}else if(strcmp(spis[i].nazwisko, spis[j].nazwisko) == 0 && strcmp(spis[i].imie, spis[j].imie) < 0){
				swapos(spis, i, j);
			}
		}
	}
}

/*
void swap(int x[IL_OSOB], int n1, int n2){
	int tmp = x[n1];
	t[n1] = x[n2];
	t[n2] = tmp;
}
*/

//=======================================================

int znajdz_nazwisko(char na[NAZW_MAX+1], char im[IMIE_MAX+1], int *p) {
	int n = 0, i = 0;
	while(n == 0 && i < IL_OSOB){
		osoba os = spis[i];
		if(strcmp(os.nazwisko, na) == 0){
			n = 1;
			strcpy(im, os.imie);
			(*p) = os.pensja;
		}
		i++;
	}
	return n;
}

//=======================================================

int znajdz_imie(char im[IMIE_MAX+1], char na[NAZW_MAX+1], int *p) {
	int n = 0, i = 0;
	while(n == 0 && i < IL_OSOB){
		osoba os = spis[i];
		if(strcmp(os.imie, im) == 0){
			n = 1;
			strcpy(na, os.nazwisko);
			(*p) = os.pensja;
		}
		i++;
	}
	return n;
}

//=======================================================

void drukuj_spis( ){
	int i;
	for(i = 0; i < IL_OSOB; i++){
		osoba os = spis[i];
		printf("%2i: %s, %s, %izł\n", i+1, os.imie, os.nazwisko, os.pensja);
	}
}

int main () {
	char odpowiedz, im[NAZW_MAX+1], na[IMIE_MAX+1];
	int p;

	utworz_spis(); sortuj_spis();
	drukuj_spis();

	do {
		printf(
		 "\n Znalezc wg imienia (I), nazwiska (N), wydrukować (S), czy zakonczyc (Q)? "
		);
		do { odpowiedz = getchar(); }
		while (isspace(odpowiedz));
			odpowiedz = tolower(odpowiedz);
		switch (odpowiedz) {
			case 's' :
				drukuj_spis();
				break;
			case 'i' :
				printf("\n szukane imie: ");
				scanf("%s", im);
				if (znajdz_imie(im, na, &p))
					printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
				else
					printf(" nie ma imienia %s\n", im);
				break;
			case 'n' :
				printf("\n szukane nazwisko: ");
				scanf("%s", na);
				if (znajdz_nazwisko(na, im, &p))
					printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
				else  printf(" nie ma nazwiska %s\n", na);
				break;
			case 'q' : break;
			default :
			  printf(" Poprawne odpowiedzi: S, N, I, Q.\n");
		}
	}  while (tolower(odpowiedz) != 'q');

	printf("\n DZIEKUJE xD.\n\n");
	return 0;
}


