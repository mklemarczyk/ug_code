
typedef enum { FALSZ=0, PRAWDA=1 }  Logiczne;

typedef struct slPoz {
  char* slowopl;
  char* slowoen;
  struct slPoz* dalej;
}*  lista;

void  inicjuj_slownik(void);
  /* powoduje, ze slownik staje sie pusty */

void drukuj_slownik(void);

Logiczne  dodaj(char* a, char* p);
  /* dodaje do slownika pare <a,p>
   * wynik  PRAWDA  oznacza, ze sie udalo dodac,
   * wynik  FALSZ  oznacza, ze slownik juz byl pelny
   */

void  usun(char* a);
  /* usuwa ze slownika pare slow, zlozona z angielskiego slowa  a
   * i jego polskiego odpowiednika
   */

void  ang_pol(char* zrodlo, char* cel);
  /* do angielskiego slowa  zrodlo
   * wyszukuje w slowniku polski odpowiednik  cel
   * jesli takiego nie ma, to pod  cel  podstawia slowo puste
   */

void  pol_ang(char* zrodlo, char* cel);
  /* do polskiego slowa  zrodlo
   * wyszukuje w slowniku angielski odpowiednik  cel
   * jesli takiego nie ma, to pod  cel  podstawia slowo puste
   */

  // zwraca wskaznik na pierwsze slowo z listy  lis
  // jesli jest pusta, to dzialanie nieokreslone
char* listCurrentPl(lista lis);

  // zwraca wskaznik na pierwsze slowo z listy  lis
  // jesli jest pusta, to dzialanie nieokreslone
char* listCurrentEn(lista lis);

lista listInsert(char* slowoen, char* slowopl, lista lis);

lista listNext(lista lis);

lista listEmpty(void);

int listIsEmpty(lista lis);

int listRemove(char* slowoen);

void listPrint(lista lis);

void listErase(lista lis);
