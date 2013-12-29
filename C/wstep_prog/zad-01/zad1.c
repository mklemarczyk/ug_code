#include <stdio.h> 
 /*wywołanie biblioteki*/
void main(){
/*glowna funkcja programu */
	int liczba; /* deklaracja zmiennej i czyli nazwa typu zmiennej oraz jej nazwa*/
	int liczba2;
	printf("To jest pierwszy program\n");
	printf("wczytujący i wypisujący 2 liczby.\n");
	printf("podaj 2 liczby wciskając enter po pierwszej z nich.\n");
	scanf("%d%d",&liczba,&liczba2);
/*
* zwroc uwage na znak ampersant w wywolaniu funkcji scanf 
* jest on niezbedny, gdyz funkcja scanf MODYFIKUJE wartość 
* zmiennej liczba. W tym celu musi mieć do niej dostęp
* i uzyskuje go przez ampersant. Dla odróżnienia: funkcja
* printf nie modyfikuje wartości zmiennych więc nie 
* trzeba wpisywać (i nie ma sensu ) ampersanta przed nazwą
* zmiennej
*/
	printf("wypisuje liczbe ktora podales/las:");
	printf("oto pierwsza: %d a to druga: %d\n",liczba,liczba2);
}
