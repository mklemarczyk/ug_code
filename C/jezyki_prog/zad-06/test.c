#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DL_SLOWA 30

char empty[MAX_DL_SLOWA] = "";

typedef struct sl {
  char slowo[MAX_DL_SLOWA];
  struct sl* dalej;
}*  lista;

//=======================================================

int pusta(lista lis) {
  // jesli  lis  jest lista pusta (wskaznik  NULL)
  // to wartoscia jest liczba rozna od 0, w przeciwnym razie 0
	if(lis == NULL){
		return 1;
	} else {
		return 0;
	}
}

//=======================================================

char* pierwsze(lista lis) {
  // zwraca wskaznik na pierwsze slowo z listy  lis
  // jesli jest pusta, to dzialanie nieokreslone
	if(pusta(lis) == 0)
		return lis->slowo;
	else
		return NULL;
}

//=======================================================

lista reszta(lista lis) {
  // zwraca liste  lis  z usunietym pierwszym slowem
  // jesli jest pusta, to dzialanie nieokreslone
	if(pusta(lis) == 0){
		return lis->dalej;
	}else{
		return NULL;
	}
}

//=======================================================

lista dolacz(char slow[MAX_DL_SLOWA], lista lis) {
  // dolacza  slowo  do poczatku listy  lis
	struct sl* tlis = (struct sl*)malloc(sizeof(struct sl));
	strcpy(tlis->slowo, slow);	
	tlis->dalej = lis;
	return tlis;
}

//=======================================================

void druk(lista lis) {
	// drukuje po kolei wszystkie slowa z  lis
	while(pusta(lis) == 0){
		printf("%s\n", pierwsze(lis));
		lis = reszta(lis);
	}
}

//=======================================================

void usun(lista lis){
	lista tmp;
	while(pusta(lis) == 0){
		tmp = reszta(lis);
		free(lis);
		lis = tmp;
    }
}

//=======================================================

lista odwroc(lista lis) {
  // odwraca liste  lis  od konca
  lista pom = NULL;
  char slowo[MAX_DL_SLOWA];
  while (! pusta(lis)) {
    strcpy(slowo, pierwsze(lis)); lis = reszta(lis);
    pom = dolacz(slowo, pom);
  }
  return pom;
}

//=======================================================

int main () {
  lista lis = NULL;
  lis = dolacz("abc", dolacz("def", dolacz("ghi", lis)));
  druk(odwroc(lis));
  usun(lis);
  return 0;
}
