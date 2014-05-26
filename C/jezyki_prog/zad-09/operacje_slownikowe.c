#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "operacje_slownikowe.h"

static lista slownik;
static int count = 0;

void  inicjuj_slownik(void){
	slownik = listEmpty();
}

Logiczne dodaj(char* a, char* p){
	slownik = listInsert(a, p, slownik);
	return PRAWDA;
}

void drukuj_slownik(void){
	listPrint(slownik);
}

void  usun(char* a){
	listRemove(a);
}

void  ang_pol(char* zrodlo, char* cel){
	lista lis = slownik;
	Logiczne koniec = FALSZ;
	while(listIsEmpty(lis) == 0 && koniec == FALSZ){
		if(strcmp(listCurrentEn(lis), zrodlo) == 0){
			strcpy(cel, listCurrentPl(lis));
			koniec = PRAWDA;
		}
		lis = listNext(lis);
	}
	if(koniec == FALSZ){
		strcpy(cel, "");
	}
}

void  pol_ang(char* zrodlo, char* cel){
	lista lis = slownik;
	Logiczne koniec = FALSZ;
	while(listIsEmpty(lis) == 0 && koniec == FALSZ){
		if(strcmp(listCurrentPl(lis), zrodlo) == 0){
			strcpy(cel, listCurrentEn(lis));
			koniec = PRAWDA;
		}
		lis = listNext(lis);
	}
	if(koniec == FALSZ){
		strcpy(cel, "");
	}
}

char* listCurrentPl(lista lis) {
	if(listIsEmpty(lis) == 0)
		return lis->slowopl;
	else
		return NULL;
}

char* listCurrentEn(lista lis) {
	if(listIsEmpty(lis) == 0)
		return lis->slowoen;
	else
		return NULL;
}

lista listInsert(char* slowoen, char* slowopl, lista lis) {
  // dolacza  slowo  do poczatku listy  lis
	lista piter = NULL;
	lista iter = lis;
	lista tlis = listEmpty();
	strcpy(tlis->slowoen, slowoen);
	strcpy(tlis->slowopl, slowopl);
	while(listIsEmpty(iter) == 0 && strcmp(listCurrentEn(iter), slowoen) < 0){
		piter = iter;
		iter = iter->dalej;
	}
	count++;
	if(piter == NULL){
		tlis->dalej = lis;
		return tlis;
	}
	piter->dalej = tlis;
	tlis->dalej = iter;
	return lis;
}

lista listNext(lista lis) {
  // zwraca liste  lis  z usunietym pierwszym slowem
  // jesli jest pusta, to dzialanie nieokreslone
	if(listIsEmpty(lis) == 0){
		return lis->dalej;
	}else{
		return NULL;
	}
}

lista listEmpty(void){
	struct slPoz* tlis = (struct slPoz*)malloc(sizeof(struct slPoz));
	tlis->slowoen = (char*)malloc(sizeof(char));
	tlis->slowopl = (char*)malloc(sizeof(char));
	return tlis;
}

int listIsEmpty(lista lis) {
  // jesli  lis  jest lista pusta (wskaznik  NULL)
  // to wartoscia jest liczba rozna od 0, w przeciwnym razie 0
	return lis == NULL;
}

int listRemove(char* slowoen){
	lista poprzednie = NULL;
	lista lis = slownik;
	Logiczne koniec = FALSZ;
	while(listIsEmpty(lis) == 0 && koniec == FALSZ){
		if(strcmp(listCurrentEn(lis), slowoen) == 0){
			if(poprzednie == NULL){
				slownik = lis->dalej;
			}else{
				poprzednie->dalej = lis->dalej;
				free(lis);
				count--;
			}
			koniec = PRAWDA;
		}
		if(koniec == FALSZ){
			poprzednie = lis;
			lis = listNext(lis);
		}
	}
	return 0;
}

void listPrint(lista lis) {
	// drukuje po kolei wszystkie slowa z  lis
	while(listIsEmpty(lis) == 0){
		printf("%s - %s\n", listCurrentEn(lis), listCurrentPl(lis));
		lis = listNext(lis);
	}
}

void listErase(lista lis){
	lista tmp;
	while(listIsEmpty(lis) == 0){
		tmp = listNext(lis);
		free(lis);
		lis = tmp;
    }
}
